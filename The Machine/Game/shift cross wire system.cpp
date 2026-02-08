//
//  shift cross wire system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "shift cross wire system.hpp"

#include "cross wire component.hpp"

namespace {
  void shift(Power &power) {
    power.prev = power.curr;
    power.curr = false;
  }
}

void shiftCrossWireSystem(entt::registry &registry) {
  auto view = registry.view<CrossWire>();
  for (const entt::entity entity : view) {
    CrossWire &cross = std::get<0>(view.get(entity));
    shift(cross.vert);
    shift(cross.hori);
  }
}
