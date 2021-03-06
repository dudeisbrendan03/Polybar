[Variables]
Discord_X=982

[Metadata]
Name=Greenlean\\Discord
Author=reddit.com/u/khanhas
Description=Click to show Discord status and control.

[DiscordIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Discord.png
W=(#Font_Size#*25/13)
X=(#Bar_OffsetX#+#Discord_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[DiscordIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"][!WriteKeyValue Variables "Curr_X" "[DiscordXPos]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "DiscordStatus.ini"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["discord://"]

[DiscordShape]
Meter=Shape
X=(#Bar_OffsetX#+#Discord_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
Shape=Rectangle ([Discord_UnreadCountBadge:X]-#Discord_X#-#Bar_OffsetX#-3),(-[DiscordIcon:H]/4),([Discord_UnreadCountBadge:W]+6*sgn([Discord_UnreadCountBadge:W])),([Discord_UnreadCountBadge:H]+2*sgn([Discord_UnreadCountBadge:W])),2 | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1

[Discord_UnreadCountBadge]
Meter=String
MeasureName=DiscordNotice
FontFace=#Font_Face#
FontSize=(#Font_Size#*10/13)
FontColor=#Color_Scheme4#
X=(#Bar_OffsetX#+#Discord_X#+[DiscordIcon:W])
StringAlign=Center
Y=(-[DiscordIcon:H]/4)r
AntiAlias=1
DynamicVariables=1

[DiscordScript]
Measure=Script
ScriptFile=#@#Scripts\Discord_Common_Script.lua
JSONFile = %appdata%\BetterDiscord\plugins\DiscordForRainmeter.config.json

[DiscordNotice]
Measure=Calc
Formula=[Taskbar_DiscordScript:GetNotification(true,true,true)]
IfCondition=DiscordNotice > 0 
IfTrueAction=[!ShowMeter Discord_UnreadCountBadge]
IfFalseAction=[!HideMeter Discord_UnreadCountBadge]
DynamicVariables=1

[DiscordXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[DiscordIcon:X]+[DiscordIcon:W]/2
DynamicVariables=1
