[Variables]
NetSpeed_X=523

[Metadata]
Name=Pratous\\NetSpeed
Author=reddit.com/u/khanhas
Description=Display download and upload speed.

[NetSpeedShape]
Meter=Shape
X=(#Bar_OffsetX#+#NetSpeed_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-#Section_Height#/2)
Shape =Rectangle -20,0,([NetSpeedIn:W]+[NetSpeedInIcon:W]+[NetSpeedOut:W]+[NetSpeedOutIcon:W] + 10*2+20+40),#Section_Height#,5 | StrokeWidth 0 | Fill Color #Color_Scheme1#
Shape2=Rectangle 0,#Section_Height#,([NetSpeedIn:W]+[NetSpeedInIcon:W]+[NetSpeedOut:W]+[NetSpeedOutIcon:W] + 10*2+20),-3,1.5 | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1

[NetSpeedInMeasure]
Measure=NetIn
Interface=Best
AverageSize=5
UpdateDivider=5

[NetSpeedInScale]
Measure=Script
;Desc: To maintain constant meter width, NetSpeedScaling_Common_Script scales
;      InputMeasure value by chosen unit's factor (1000 or 1024) but it always 
;      start to scale at 1000. It also appends unit to the result.
;Opts:
;      InputMeasure : NetIn or NetOut measure name.
;      NumOfNum: number of characters of output, has to be equal or larger
;                 than 3 (not including dot character).
;      Unit: Valid options:
;            db: Decimal multiples of bits (kb, Mb, Gb)
;            bb: Binary multiples of bits (Kibit, Mibit, Gibit)
;            dB: Decimal multiples of bytes (kB, MB, GB)
;            bB: Binary multiples of bytes (KiB, MiB, GiB)
;      More info about unit: https://en.wikipedia.org/wiki/Data_rate_units
ScriptFile=#@#Scripts\NetSpeedScaling_Common_Script.lua
InputMeasure=NetSpeedInMeasure
NumOfNum=4
Unit = dB
;Uncomment 2 lines below to have a space between value and unit.
;RegExpSubstitute=1
;Substitute="([^0-9\.]+)":" \1"

[NetSpeedOutMeasure]
Measure=NetOut
Interface=Best
AverageSize=5
UpdateDivider=5

[NetSpeedOutScale]
Measure=Script
ScriptFile=#@#Scripts\NetSpeedScaling_Common_Script.lua
InputMeasure=NetSpeedOutMeasure
NumOfNum=4
Unit = dB
;RegExpSubstitute=1
;Substitute="([^0-9\.]+)":" \1"

[NetSpeedInIcon]
Meter=String
Text=[\xE2C4]
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#NetSpeed_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[NetSpeedIn]
Meter=String
MeasureName=NetSpeedInScale
Text=%1/s
FontFace=#Font_Face2#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r

[NetSpeedOutIcon]
Meter=String
MeterStyle=NetSpeedInIcon
Text=[\xE2C6]
X=20R

[NetSpeedOut]
Meter=String
MeterStyle=NetSpeedIn
MeasureName=NetSpeedOutScale
