#include "MainComponent.h"


    //==============================================================================
    MainComponent::MainComponent()
    {
        setSize(originalWidth, originalHeight);
            

        addAndMakeVisible(PowerSwitch);
        PowerSwitch.addChangeListener(&LEDButton1);
        addAndMakeVisible(LEDButton1);

        FootSwitch.addChangeListener(&LEDButton2);
        addAndMakeVisible(FootSwitch);
        addAndMakeVisible(LEDButton2);
        
    }

    MainComponent::~MainComponent()
    {
        FootSwitch.removeChangeListener(&LEDButton2);
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

        PowerSwitch.setBounds(15, 250, 100, 100);
        LEDButton1.setBounds(40, 100, 50, 50);

        
        FootSwitch.setBounds(300, 250, 175, 160);
        LEDButton2.setBounds(340, 100, 50, 50);
    }



