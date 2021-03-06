[Variables]
Power_X=1351

[Metadata]
Name=Greenlean\\Power
Author=reddit.com/u/khanhas
Description=Click to activate Power menu to Turn Off, Restart, Sleep or Log off.

[PowerShape]
Meter=Shape
X=(#Bar_OffsetX#+#Power_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,#Tile_Space#,([PowerButton:W]+#Bar_Height#/2),(#Bar_Height#-2*#Tile_Space#) | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color #Color_Scheme3#
DynamicVariables=1

[PowerCurrYCalc]
Measure=Calc
Formula=SubSkinDirectionCalc = 1 ? (#CURRENTCONFIGY# + #Bar_OffsetY#) : (#CURRENTCONFIGY# + #Bar_OffsetY# + #Bar_Height#) 
IfCondition=SubSkinDirectionCalc = 1
IfTrueAction=[!SetVariable PowerReplaceChar ][!WriteKeyValue Variables Dir 1 "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"]
IfFalseAction=[!SetVariable PowerReplaceChar ][!WriteKeyValue Variables Dir 0 "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"]
DynamicVariables=1

[PowerButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=([PowerButton:W]/2+#Bar_Height#/4)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=[!Log "([PowerButton:W]+#Bar_Height#)"][!SetOption #CURRENTSECTION# Text #PowerReplaceChar#][!UpdateMeter PowerButton][!Redraw][!WriteKeyValue Variables Curr_X (#Bar_OffsetX#+#Power_X#+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!WriteKeyValue Variables Curr_Y [PowerCurrYCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\PowerMenu.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "PowerMenu.ini"]
