#include "MainComponent.h"


    //==============================================================================
    MainComponent::MainComponent()
    {
        setSize(originalWidth, originalHeight);
       

       // toggleSwitchButton.onClick = [this] { toggleSwitchButtonState = !toggleSwitchButtonState ; redraw();};


        toggleSwitchLed.setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);
        addAndMakeVisible(toggleSwitchLed);


 
             
        FootSwitch.addChangeListener(&LEDButton);
        addAndMakeVisible(FootSwitch);
        addAndMakeVisible(LEDButton);
        
    }

    MainComponent::~MainComponent()
    {
        FootSwitch.removeChangeListener(&LEDButton);
    }

    //==============================================================================
    void MainComponent::paint(juce::Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

        g.setFont(juce::Font(16.0f));
        g.setColour(juce::Colours::white);
        
    }

    void MainComponent::resized()
    {
        // This is called when the MainComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.

        toggleSwitchButton.setBounds(9, 250, 35, 45);
        toggleSwitchLed.setBounds(40, 100, 35, 45);

        
        FootSwitch.setBounds(300, 250, 175, 160);
        LEDButton.setBounds(340, 100, 50, 50);
    }



