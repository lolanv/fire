#include "Engine.h"

Engine::Engine(EngineType type, float horsepower, const std::string &number, EngineCylinder cylinder, float torque)
    : _engine_type(type), _engine_horsepower(horsepower), _engine_number(number),
      _engine_cylinder(cylinder), _engine_torque(torque) {}

