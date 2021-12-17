#{
#	pane id "com.apple.preference.universalaccess" of application "System Preferences",
#	pane id "com.apple.preferences.Bluetooth" of application "System Preferences",
#	pane id "com.apple.preference.datetime" of application "System Preferences",
#	pane id "com.apple.preference.desktopscreeneffect" of application "System Preferences",
#	pane id "com.apple.preference.displays" of application "System Preferences",
#	pane id "com.apple.preference.dock" of application "System Preferences",
#	pane id "com.apple.preference.energysaver" of application "System Preferences",
#	pane id "com.apple.preferences.extensions" of application "System Preferences",
#	pane id "com.apple.preference.general" of application "System Preferences",
#	pane id "com.apple.preferences.internetaccounts" of application "System Preferences",
#	pane id "com.apple.preference.keyboard" of application "System Preferences",
#	pane id "com.apple.Localization" of application "System Preferences",
#	pane id "com.apple.preference.expose" of application "System Preferences",
#	pane id "com.apple.preference.mouse" of application "System Preferences",
#	pane id "com.apple.preference.network" of application "System Preferences",
#	pane id "com.apple.preference.notifications" of application "System Preferences",
#	pane id "com.apple.preference.printfax" of application "System Preferences",
#	pane id "com.apple.preference.screentime" of application "System Preferences",
#	pane id "com.apple.preference.security" of application "System Preferences",
#	pane id "com.apple.preferences.sharing" of application "System Preferences",
#	pane id "com.apple.preference.sidecar" of application "System Preferences",
#	pane id "com.apple.preference.speech" of application "System Preferences",
#	pane id "com.apple.preferences.softwareupdate" of application "System Preferences",
#	pane id "com.apple.preference.sound" of application "System Preferences",
#	pane id "com.apple.preference.spotlight" of application "System Preferences",
#	pane id "com.apple.preference.startupdisk" of application "System Preferences",
#	pane id "com.apple.prefs.backup" of application "System Preferences",
#	pane id "com.apple.preference.trackpad" of application "System Preferences",
#	pane id "com.apple.preferences.users" of application "System Preferences",
#}

tell application "System Preferences"
	activate
	#reveal pane id "com.apple.preference.general"
	#reveal pane id "com.apple.preference.keyboard"
	#tell pane id "com.apple.preferences.Bluetooth" to anchors
end tell

tell application "System Events"
	tell process "System Preferences"
		click checkbox "Example Checkbox" of sheet 1 of window 1
	end tell
end tell
