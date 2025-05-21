/*
 * Copyright (C) 2024-2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "framework/argument/boolean_flag_argument.h"
#include "framework/argument/enum/graph_structure_argument.h"
#include "framework/test_case/test_case.h"

struct FinalizeGraphArguments : TestCaseArgumentContainer {
    BooleanFlagArgument firstFinalizeOnly;
    GraphStructureArgument graphStructure;

    FinalizeGraphArguments() : firstFinalizeOnly(*this, "firstFinalizeOnly", "Only measure the first finalize of a modifiable graph, since multiple finalizes of the same graph may cache some information."),
                               graphStructure(*this, "graphStructure", "Graph structure to use for this test based on common use cases.") {}
};

struct FinalizeGraph : TestCase<FinalizeGraphArguments> {
    using TestCase<FinalizeGraphArguments>::TestCase;

    std::string getTestCaseName() const override {
        return "FinalizeGraph";
    }

    std::string getHelp() const override {
        return "measures time spent in finalizing a graph in SYCL on CPU.";
    }
};
