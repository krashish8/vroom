#ifndef STEP_H
#define STEP_H

/*

This file is part of VROOM.

Copyright (c) 2015-2021, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <string>

#include "structures/vroom/break.h"
#include "structures/vroom/job.h"
#include "structures/vroom/location.h"
#include "structures/vroom/solution/violations.h"

namespace vroom {

struct Step {
  const STEP_TYPE step_type;
  const JOB_TYPE job_type;
  const Location location;
  const Id id;
  const Duration setup;
  const Duration service;
  const Amount load;
  const std::string description;

  Duration arrival;
  Duration duration;
  Duration waiting_time;
  Distance distance;

  Violations violations;

  Step(STEP_TYPE type, Location location, const Amount& load);

  Step(const Job& job, const Duration setup, const Amount& load);

  Step(const Break& b, const Amount& load);
};

} // namespace vroom

#endif
