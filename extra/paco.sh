#!/bin/sh

echo 'on run
    -- check if Terminal is already running
    tell application "System Events"
        set isRunning to (exists process "Terminal")
    end tell
    tell application "Terminal"
        -- if Terminal is running create new window
        if isRunning then do script ""
        activate
        -- some command to execute
        do script "cd /Users/mamagalh/42Projects/get_next_line/proj && paco" in front window
    end tell
end run' | osascript -