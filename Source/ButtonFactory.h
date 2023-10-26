/*
  ==============================================================================

    ButtonFactory.h
    Created: 14 Oct 2023 11:51:23am
    Author:  mert.kabukcuoglu

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace juce
{

class CustomButtonFactory
{
public:
    struct footSwitchButton : ImageButton, ChangeBroadcaster
    {
        footSwitchButton();
        void mouseDown(const MouseEvent&)override;
        void mouseUp(const MouseEvent&)override;
        void redraw();
        bool isDown{false};
    };
    
    struct LED: ImageButton, ChangeListener
    {
        LED();
        void redraw();
        void changeListenerCallback(ChangeBroadcaster *)override;
        bool isOn{false};     
    };

    struct toggleSwitchButton : ImageButton, ChangeBroadcaster
    {
        toggleSwitchButton();
        void clicked() override;
        void redraw();
        bool isOn{false};
    };

    struct dynamicSVGButton : DrawableButton
    {
        dynamicSVGButton(const String& buttonName, ButtonStyle buttonStyle);
    };

};



}
