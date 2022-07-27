//=- LoongArchISelDAGToDAG.h - A dag to dag inst selector for LoongArch ---===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the LoongArch target.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_LOONGARCH_LOONGARCHISELDAGTODAG_H
#define LLVM_LIB_TARGET_LOONGARCH_LOONGARCHISELDAGTODAG_H

#include "LoongArch.h"
#include "LoongArchTargetMachine.h"
#include "llvm/CodeGen/SelectionDAGISel.h"

// LoongArch-specific code to select LoongArch machine instructions for
// SelectionDAG operations.
namespace llvm {
class LoongArchDAGToDAGISel : public SelectionDAGISel {
  const LoongArchSubtarget *Subtarget = nullptr;

public:
  explicit LoongArchDAGToDAGISel(LoongArchTargetMachine &TM)
      : SelectionDAGISel(TM) {}

  StringRef getPassName() const override {
    return "LoongArch DAG->DAG Pattern Instruction Selection";
  }

  bool runOnMachineFunction(MachineFunction &MF) override {
    Subtarget = &MF.getSubtarget<LoongArchSubtarget>();
    return SelectionDAGISel::runOnMachineFunction(MF);
  }

  void Select(SDNode *Node) override;

  bool SelectBaseAddr(SDValue Addr, SDValue &Base);

  bool selectShiftMask(SDValue N, unsigned ShiftWidth, SDValue &ShAmt);
  bool selectShiftMaskGRLen(SDValue N, SDValue &ShAmt) {
    return selectShiftMask(N, Subtarget->getGRLen(), ShAmt);
  }
  bool selectShiftMask32(SDValue N, SDValue &ShAmt) {
    return selectShiftMask(N, 32, ShAmt);
  }

  bool selectSExti32(SDValue N, SDValue &Val);
  bool selectZExti32(SDValue N, SDValue &Val);

// Include the pieces autogenerated from the target description.
#include "LoongArchGenDAGISel.inc"
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_LOONGARCH_LOONGARCHISELDAGTODAG_H
