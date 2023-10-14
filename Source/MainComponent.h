#pragma once

#include <JuceHeader.h>

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

    void toggleSwitchButtonClicked();
    bool toggleSwitchButtonState{ false };

    bool footSwitchButtonPressed{ false };
    bool footSwitchButtonState{ false };

    void redraw();


private:
    //==============================================================================
    // Your private member variables go here...
    static constexpr int originalWidth{ 800 };
    static constexpr int originalHeight{ 400 };

    juce::ImageButton toggleSwitchButton;
    juce::ImageButton toggleSwitchLed;
    
    juce::ImageButton footSwitchButton;
    juce::ImageButton footSwitchLed;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
