/*
 * Copyright (C) 2022-2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "definitions/stream_memory.h"

#include "framework/test_case/register_test_case.h"
#include "framework/utility/common_gtest_args.h"
#include "framework/utility/memory_constants.h"

#include <gtest/gtest.h>

[[maybe_unused]] static const inline RegisterTestCase<StreamMemory> registerTestCase{};

class StreamMemoryTest : public ::testing::TestWithParam<std::tuple<Api, StreamMemoryType, size_t, bool, UsmMemoryPlacement>> {
};

TEST_P(StreamMemoryTest, Test) {
    StreamMemoryArguments args;
    args.api = std::get<0>(GetParam());
    args.type = std::get<1>(GetParam());
    args.size = std::get<2>(GetParam());
    args.useEvents = std::get<3>(GetParam());
    args.memoryPlacement = std::get<4>(GetParam());

    StreamMemory test;
    test.run(args);
}

using namespace MemoryConstants;
INSTANTIATE_TEST_SUITE_P(
    StreamMemoryTest,
    StreamMemoryTest,
    ::testing::Combine(
        ::CommonGtestArgs::allApis(),
        ::testing::ValuesIn(StreamMemoryTypeArgument::enumValues),
        ::testing::Values(1 * megaByte, 8 * megaByte, 32 * megaByte, 128 * megaByte, 512 * megaByte, 1 * gigaByte),
        ::testing::Values(false, true),
        ::testing::ValuesIn(UsmMemoryPlacementArgument::deviceAndHost)));
