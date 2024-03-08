#ifndef ENGINE_H
#define ENGINE_H

#include <string>

enum EngineType
{
    TURBOCHARGED,
    REGULAR
};
enum EngineCylinder
{
    CYLINDER_4,
    CYLINDER_6
};

class Engine
{
private:
    EngineType _engine_type;
    float _engine_horsepower;
    std::string _engine_number;
    EngineCylinder _engine_cylinder;
    float _engine_torque;

public:
    Engine(EngineType type, float horsepower, const std::string &number, EngineCylinder cylinder, float torque);

    EngineType Engine::getEngineType() const { return _engine_type; }
    float Engine::getEngineHorsepower() const { return _engine_horsepower; }
    std::string Engine::getEngineNumber() const { return _engine_number; }
    EngineCylinder Engine::getEngineCylinder() const { return _engine_cylinder; }
    float Engine::getEngineTorque() const { return _engine_torque; }
};

#endif // ENGINE_H
