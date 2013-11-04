/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "hiopl.h"
#include "FloatParameter.h"


//==============================================================================
/**
*/
class JuceOplvstiAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    JuceOplvstiAudioProcessor();
	void initPrograms();
    ~JuceOplvstiAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);
	void setEnumParameter (String name, int newValue);
	void setIntParameter (String name, int newValue);
	int getIntParameter (String name);
	int getEnumParameter (String name);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

private:
	Hiopl *Opl;
	std::vector<FloatParameter*> params;
	std::map<String, int> paramIdxByName;
	std::map<String, std::vector<float>> programs;
	std::vector<String> program_order;
	int i_program;
	bool velocity;
	static const int NO_NOTE=-1;
	int active_notes[Hiopl::CHANNELS+1];	// keyed by channel

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceOplvstiAudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED