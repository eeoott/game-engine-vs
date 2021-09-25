#include "BaseApplication.hpp"
#include <iostream>

using namespace GEVS;

bool GEVS::BaseApplication::m_bQuit = false;

GEVS::BaseApplication::BaseApplication(GfxConfiguration& cfg)
    : m_Config(cfg)
{

}


int GEVS::BaseApplication::Initialize()
{
    //m_bQuit = false;
    std::cout << m_Config;

    return 0;
}

void GEVS::BaseApplication::Finalize()
{

}

void GEVS::BaseApplication::Tick()
{

}

bool GEVS::BaseApplication::IsQuit()
{
    return m_bQuit;
}