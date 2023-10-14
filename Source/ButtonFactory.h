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
    struct testButton: ImageButton
    {
        testButton();
        void mouseDown(const MouseEvent&)override;
        //void mouseEnter();
    };
};



}
