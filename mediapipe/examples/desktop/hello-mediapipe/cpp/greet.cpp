#include "greet.hpp"

#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/port/status.h"
#include "mediapipe/framework/port/canonical_errors.h"

#include <string>
#include <iostream>
#include <cstdio>

namespace mediapipe {

void Greet::SayHello()
{
    auto status = PrintHelloWorld();
    if (!status.ok()) {
        LOG(INFO) << "Unknown error: status = " << status << std::endl;
    }
}

absl::Status Greet::PrintHelloWorld()
{
    std::string protoG = R"(
    input_stream: "in"
    output_stream: "out"
    node {
        calculator: "PassThroughCalculator"
        input_stream: "in"
        output_stream: "out1"
    }
    node {
        calculator: "PassThroughCalculator"
        input_stream: "out1"
        output_stream: "out"
    }
    )";

    mediapipe::CalculatorGraphConfig config = mediapipe::ParseTextProtoOrDie<mediapipe::CalculatorGraphConfig>(protoG);
    mediapipe::CalculatorGraph graph;
    MP_RETURN_IF_ERROR(graph.Initialize(config));

    auto cb = [](const mediapipe::Packet &packet)->mediapipe::Status{
        LOG(INFO) << packet.Timestamp() << ": HELLO " << packet.Get<double>();
        return mediapipe::OkStatus();
    };

    MP_RETURN_IF_ERROR(graph.ObserveOutputStream("out", cb));

    MP_RETURN_IF_ERROR(graph.StartRun({}));

    for (int i=0; i<13; ++i) {
        mediapipe::Timestamp ts(i);
        mediapipe::Packet packet = mediapipe::MakePacket<double>(i*0.1).At(ts);
        MP_RETURN_IF_ERROR(graph.AddPacketToInputStream("in", packet));
    }
    graph.CloseInputStream("in");

    MP_RETURN_IF_ERROR(graph.WaitUntilDone());

    return mediapipe::OkStatus();
}

}  // namespace mediapipe

