function DeviceList()
    local deviceList = SKIN:GetMeasure('MeasureDeviceList'):GetStringValue()
    local i = 1
	
        for name in string.gmatch(deviceList, '{[.%d]*}.{[%x-]*}: ([^\n]*)') do
		
            if i == 1 then
				index = ''
			else
				index = i 
			end
			
			SKIN:Bang('!SetOption', i, 'Text', name)
			SKIN:Bang('!SetVariable', 'NumberOfItems', i + 2)
			i = i + 1

        end
end