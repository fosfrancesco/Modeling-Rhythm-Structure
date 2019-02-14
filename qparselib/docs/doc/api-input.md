# group `input` {#group__input}

The `input` module contains utilities for reading from and writing to files the data given in input to the quantization by parsing algorithm (schema and segment).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`InputSegmentMIDI`](api-input.md#classInputSegmentMIDI) | import an [InputSegment](api-segment.md#classInputSegment) from a MIDI file.
`class `[`InputSegmentSerial`](api-input.md#classInputSegmentSerial) | serialization of an input segment in a text file.
`class `[`WTAFile`](api-input.md#classWTAFile) | wrapper for constructing [WTA](api-schemata.md#classWTA) with various flags for weight type.

# class `InputSegmentMIDI` {#classInputSegmentMIDI}

```
class InputSegmentMIDI
  : public InputSegment
```  

import an [InputSegment](#classInputSegment) from a MIDI file.

* The segment contains the NOTE-ON and NOTE-OFF events in the MIDI file, with the realtime dates.

* The musical dates and duration as set to unknown.

* Every NOTE_ON event is linked to the closest posteroir NOTE-OFF event with the same MIDI key. It is left unmatched (without warning) if there is no such matching NOTE-OFF.

* Several NOTE-ON with the same key may be linked to the same NOTE-OFF (a warning is displayed in this case).

* Unmatched NOTE-OFF are added with a warning.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a8ae9a7a113d9b3fec0643cf8773a69df)`(const std::string filename,int tracknb)` | read input segment from a MIDI file.
`public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1ad337626161ab1a2ff80a4d845421a9f6)`(MidiFile & midifile,int tracknb)` | read input segment from a MIDI file.
`public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a97c065fd510e9a925e12e44b6378f394)`(const std::string filename,bool mono,bool norest,int tracknb)` | read input segment from a MIDI file.
`public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a6a5548fa47cfe652b80b0e7dcfcf9735)`(const `[`InputSegmentMIDI`](#classInputSegmentMIDI)` &)` | 
`public inline virtual  `[`~InputSegmentMIDI`](#classInputSegmentMIDI_1ab7134dc1b01d7f45b95df4b2b448a716)`()` | 
`public inline std::string `[`filename`](#classInputSegmentMIDI_1a55fbf779b44ae82b17bad1f2839c8c78)`() const` | 
`public size_t `[`export_midifile`](#classInputSegmentMIDI_1a936c91d6d4d71d1e968808064455e9d4)`(std::string,`[`Rational`](#classRational)`)` | copy input midifile into output_midifile.
`public inline size_t `[`status`](#classInputSegmentMIDI_1a647bb0ebc71484c531c13ded3a86839c)`() const` | exit status code for MIDI import
`public size_t `[`export_midifile`](#classInputSegmentMIDI_1a6c0b140ef054db3d0669ffbb11c8c29b)`(MidiFile & midifile,std::string midiout,`[`Rational`](#classRational)` beatperbar)` | copy input midifile into output_midifile.
`public size_t `[`export_midifile_mono`](#classInputSegmentMIDI_1af2ac856f11e5ebbca039e988e0df0d9d)`(MidiFile & midifile,std::string midiout,`[`Rational`](#classRational)` beatperbar)` | copy input midifile into output_midifile, monophonic case.

## Members

#### `public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a8ae9a7a113d9b3fec0643cf8773a69df)`(const std::string filename,int tracknb)` {#classInputSegmentMIDI_1a8ae9a7a113d9b3fec0643cf8773a69df}

read input segment from a MIDI file.

The musical onsets and durations are all set to UNKNOWN. 
#### Parameters
* `filename` name of input MIDI file 

* `tracknb` MIDI track read

#### `public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1ad337626161ab1a2ff80a4d845421a9f6)`(MidiFile & midifile,int tracknb)` {#classInputSegmentMIDI_1ad337626161ab1a2ff80a4d845421a9f6}

read input segment from a MIDI file.

The musical onsets and durations are all set to UNKNOWN. 
#### Parameters
* `midifile` a MIDIfile object 

* `tracknb` MIDI track read

#### `public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a97c065fd510e9a925e12e44b6378f394)`(const std::string filename,bool mono,bool norest,int tracknb)` {#classInputSegmentMIDI_1a97c065fd510e9a925e12e44b6378f394}

read input segment from a MIDI file.

the musical onsets and durations are all set to -1 for backward compatibility. TBR 
#### Parameters
* `mono` flag : set if we want a monophonic input segment. 

* `norest` flag : if set, rests in MIDI file are ignored.

#### `public  `[`InputSegmentMIDI`](#classInputSegmentMIDI_1a6a5548fa47cfe652b80b0e7dcfcf9735)`(const `[`InputSegmentMIDI`](#classInputSegmentMIDI)` &)` {#classInputSegmentMIDI_1a6a5548fa47cfe652b80b0e7dcfcf9735}

#### `public inline virtual  `[`~InputSegmentMIDI`](#classInputSegmentMIDI_1ab7134dc1b01d7f45b95df4b2b448a716)`()` {#classInputSegmentMIDI_1ab7134dc1b01d7f45b95df4b2b448a716}

#### `public inline std::string `[`filename`](#classInputSegmentMIDI_1a55fbf779b44ae82b17bad1f2839c8c78)`() const` {#classInputSegmentMIDI_1a55fbf779b44ae82b17bad1f2839c8c78}

#### `public size_t `[`export_midifile`](#classInputSegmentMIDI_1a936c91d6d4d71d1e968808064455e9d4)`(std::string,`[`Rational`](#classRational)`)` {#classInputSegmentMIDI_1a936c91d6d4d71d1e968808064455e9d4}

copy input midifile into output_midifile.

update the onsets / offsets to the quantized values in this segment. this segment must have been created from a midi file. 

the musical date and duration must have been set in this segment.

#### `public inline size_t `[`status`](#classInputSegmentMIDI_1a647bb0ebc71484c531c13ded3a86839c)`() const` {#classInputSegmentMIDI_1a647bb0ebc71484c531c13ded3a86839c}

exit status code for MIDI import

#### Returns
0 if import or export worked well 

#### Returns
error code > 0 otherwise

#### `public size_t `[`export_midifile`](#classInputSegmentMIDI_1a6c0b140ef054db3d0669ffbb11c8c29b)`(MidiFile & midifile,std::string midiout,`[`Rational`](#classRational)` beatperbar)` {#classInputSegmentMIDI_1a6c0b140ef054db3d0669ffbb11c8c29b}

copy input midifile into output_midifile.

update the onsets / offsets to the quantized values in this segment. 
#### Parameters
* `midifile` MIDIfile struct 

* `midiout` name of output midifile 

* `beatperbar` number of beats per bar (for producing output midifile) 

this segment must have been created from a midi file. 

the musical date and duration must have been set in this segment.

TBR mv export to segment/InputSegment* classes

#### `public size_t `[`export_midifile_mono`](#classInputSegmentMIDI_1af2ac856f11e5ebbca039e988e0df0d9d)`(MidiFile & midifile,std::string midiout,`[`Rational`](#classRational)` beatperbar)` {#classInputSegmentMIDI_1af2ac856f11e5ebbca039e988e0df0d9d}

copy input midifile into output_midifile, monophonic case.

update the onsets / offsets to the quantized values in this segment. 
#### Parameters
* `midifile` MIDIfile struct 

* `midiout` name of output midifile 

* `beatperbar` number of beats per bar (for producing output midifile) 

this segment must have been created from a midi file. 

the musical date and duration must have been set in this segment.

TBR mv export to segment/InputSegment* classes

# class `InputSegmentSerial` {#classInputSegmentSerial}

```
class InputSegmentSerial
  : public InputSegment
```  

serialization of an input segment in a text file.

functions for import, export and comparison (evaluation).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InputSegmentSerial`](#classInputSegmentSerial_1a82aef1422a814f19a81b8e15b7979f73)`(const std::string filename,bool mono)` | read input segment from a text file.
`public  `[`InputSegmentSerial`](#classInputSegmentSerial_1ac55f2e5708436d8db1a7c2f8dc23436d)`(const `[`InputSegmentSerial`](#classInputSegmentSerial)` &)` | 
`public inline virtual  `[`~InputSegmentSerial`](#classInputSegmentSerial_1afe24d11b6aa7704975049e67c4d8e22a)`()` | 
`public inline std::string `[`filename`](#classInputSegmentSerial_1a4f66455606aaca9a289919b59c005991)`() const` | 
`public size_t `[`save`](#classInputSegmentSerial_1af1c586a042acb96f1e73807f423a039c)`(const std::string filename)` | export this input segment into given file.
`public inline size_t `[`status`](#classInputSegmentSerial_1acaa3917f1ab9800b80155b8e1c16270d)`() const` | return the final status for import.

## Members

#### `public  `[`InputSegmentSerial`](#classInputSegmentSerial_1a82aef1422a814f19a81b8e15b7979f73)`(const std::string filename,bool mono)` {#classInputSegmentSerial_1a82aef1422a814f19a81b8e15b7979f73}

read input segment from a text file.

#### Parameters
* `filename` name of input text file 

* `mono` flag is true if we want a monophonic input segment.

if not present in text file, the musical onsets and durations are all set to -1.

#### `public  `[`InputSegmentSerial`](#classInputSegmentSerial_1ac55f2e5708436d8db1a7c2f8dc23436d)`(const `[`InputSegmentSerial`](#classInputSegmentSerial)` &)` {#classInputSegmentSerial_1ac55f2e5708436d8db1a7c2f8dc23436d}

#### `public inline virtual  `[`~InputSegmentSerial`](#classInputSegmentSerial_1afe24d11b6aa7704975049e67c4d8e22a)`()` {#classInputSegmentSerial_1afe24d11b6aa7704975049e67c4d8e22a}

#### `public inline std::string `[`filename`](#classInputSegmentSerial_1a4f66455606aaca9a289919b59c005991)`() const` {#classInputSegmentSerial_1a4f66455606aaca9a289919b59c005991}

#### `public size_t `[`save`](#classInputSegmentSerial_1af1c586a042acb96f1e73807f423a039c)`(const std::string filename)` {#classInputSegmentSerial_1af1c586a042acb96f1e73807f423a039c}

export this input segment into given file.

#### `public inline size_t `[`status`](#classInputSegmentSerial_1acaa3917f1ab9800b80155b8e1c16270d)`() const` {#classInputSegmentSerial_1acaa3917f1ab9800b80155b8e1c16270d}

return the final status for import.

#### Returns
0 if import or export worked well 

#### Returns
error code > 0 otherwise

# class `WTAFile` {#classWTAFile}

```
class WTAFile
  : public WTA
```  

wrapper for constructing [WTA](#classWTA) with various flags for weight type.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`WTAFile`](#classWTAFile_1afc385786a0b36382ab366c91a8b9ce0b)`()` | default constructor for cython.
`public  `[`WTAFile`](#classWTAFile_1a0c65f030a8df8bdb8eed5c261908e6bb)`(const std::string filename,`[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560)` wt,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` | read weight type and schema from file.
`public  `[`WTAFile`](#classWTAFile_1a1d76575338801558fc75759aa90261b9)`(const std::string filename,bool count_flag,bool penalty_flag,bool stochastic_flag)` | read schema from file
`public  `[`~WTAFile`](#classWTAFile_1acd30482d9409353945f35dbaf3fd05f1)`()` | same as [WTA](api-schemata.md#classWTA) destructor.
`public size_t `[`save`](#classWTAFile_1a01b3ef064d42d02129f4fc202935e805)`(string filename)` | save to file.

## Members

#### `public  `[`WTAFile`](#classWTAFile_1afc385786a0b36382ab366c91a8b9ce0b)`()` {#classWTAFile_1afc385786a0b36382ab366c91a8b9ce0b}

default constructor for cython.

#### `public  `[`WTAFile`](#classWTAFile_1a0c65f030a8df8bdb8eed5c261908e6bb)`(const std::string filename,`[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560)` wt,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#classWTAFile_1a0c65f030a8df8bdb8eed5c261908e6bb}

read weight type and schema from file.

#### Parameters
* `filename` input text file specifying the schema 

* `wt` weight type (forced)

if another weight type is given as argument (forced weight type)

* use it as weight type for reading schema if no weight type found in file

* use it to cast schema (force type). the [WTA](#classWTA) can be empty in case of error.

#### `public  `[`WTAFile`](#classWTAFile_1a1d76575338801558fc75759aa90261b9)`(const std::string filename,bool count_flag,bool penalty_flag,bool stochastic_flag)` {#classWTAFile_1a1d76575338801558fc75759aa90261b9}

read schema from file

#### Parameters
* `filename` input text file specifying the schema 

* `count_flag` flag to determine the type of weights 

* `penalty_flag` flag to determine the type of weights 

* `stochastic_flag` flag to determine the type of weights

casts weights according to compile options if needed.

TODO: TBR

#### `public  `[`~WTAFile`](#classWTAFile_1acd30482d9409353945f35dbaf3fd05f1)`()` {#classWTAFile_1acd30482d9409353945f35dbaf3fd05f1}

same as [WTA](#classWTA) destructor.

#### `public size_t `[`save`](#classWTAFile_1a01b3ef064d42d02129f4fc202935e805)`(string filename)` {#classWTAFile_1a01b3ef064d42d02129f4fc202935e805}

save to file.

