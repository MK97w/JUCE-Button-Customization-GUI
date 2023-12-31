#pragma once

#include <JuceHeader.h>
#include "ButtonFactory.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    //==============================================================================
    // Your private member variables go here...
    static constexpr int originalWidth{ 800 };
    static constexpr int originalHeight{ 400 };

    juce::CustomButtonFactory::toggleSwitchButton PowerSwitch;
    juce::CustomButtonFactory::LED LEDButton1;
    
   // juce::ImageButton footSwitchButton;
  //  juce::ImageButton footSwitchLed;
    
    juce::CustomButtonFactory::footSwitchButton FootSwitch;
    juce::CustomButtonFactory::LED LEDButton2;


    juce::CustomButtonFactory::dynamicSVGButton Metronome;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
