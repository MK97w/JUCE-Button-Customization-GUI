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
    struct testButton: ImageButton, ChangeBroadcaster
    {
        testButton();
        void mouseDown(const MouseEvent&)override;
        void mouseUp(const MouseEvent&)override;
        void redraw();
        bool isDown{false};
    };
    
    struct testLED: ImageButton, ChangeListener
    {
        testLED();
        void redraw();
        void changeListenerCallback(ChangeBroadcaster *)override;
        bool isOn{false};
        
    };
};



}
