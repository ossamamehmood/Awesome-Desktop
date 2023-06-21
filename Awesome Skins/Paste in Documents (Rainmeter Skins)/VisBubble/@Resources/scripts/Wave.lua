-- @author Malody Hoe / GitHub: undefinist / Twitter: undefinist

function Initialize()
	NumOfItems = SKIN:ParseFormula(SKIN:GetVariable("NumOfItems"))
	Radius = SKIN:ParseFormula(SKIN:GetVariable("Radius"))
	RadiusY = SKIN:ParseFormula(SKIN:GetVariable("RadiusY"))
	ExtrudeMax = SKIN:ParseFormula(SKIN:GetVariable("ExtrudeMax"))
	ExtrudeMin = SKIN:ParseFormula(SKIN:GetVariable("ExtrudeMin"))
	Inward = SKIN:ParseFormula(SKIN:GetVariable("Inward"))
	AngleStart = SKIN:ParseFormula(SKIN:GetVariable("AngleStart"))
	AngleTotal = SKIN:ParseFormula(SKIN:GetVariable("AngleTotal"))
	ClockWise = SKIN:ParseFormula(SKIN:GetVariable("ClockWise")) == 1
	Smoothing = SKIN:ParseFormula(SKIN:GetVariable("Smoothing"))
	WaveFilled = SKIN:ParseFormula(SKIN:GetVariable("WaveFilled")) == 1
	Multi = SELF:GetOption("Multi") == "1"
	PI = math.pi
	PIx2 = math.pi * 2
	
	measures = {}
	curve = {}
	for i = 0,NumOfItems-1 do
		table.insert(measures, SKIN:GetMeasure("mBand" .. i))
	end
	
	if Multi then
		measuresR = {}
		for i = 0,NumOfItems-1 do
			table.insert(measuresR, SKIN:GetMeasure("mBandR" .. i))
		end
	end
end

function Update()
	if Multi then process("R") end
	process()
end

function process(prefix)
	if prefix == nil then prefix = "" end
	
	local bands = {}
	for i = 1,#measures do
		if prefix == "" then 
			table.insert(bands, measures[i]:GetValue())
		else
			table.insert(bands, measuresR[i]:GetValue())
		end
	end

	sx = 0
	sy = 0
	curve = {}
	local pts = {}

	local nLines = NumOfItems
	local completeCircle = true
	if AngleTotal < PIx2 then
		completeCircle = false
		nLines = nLines - 1
	end

	-- obtain the points
	for i = 1, nLines do
		local mband0 = bands[i]
		local iNext = i + 1
		local iPrev = i - 1
		if completeCircle then
			if iNext > nLines then iNext = 1 end
			if iPrev < 1 then iPrev = nLines end
		else		
			if iNext > nLines then iNext = i end
			if iPrev < 1 then iPrev = i end
		end
		local mbandNext = bands[iNext]
		local mbandPrev = bands[iPrev]
	
		--local mband0 = SKIN:GetMeasure("mBand" .. prefix .. i):GetValue()
		--local mbandNext = SKIN:GetMeasure("mBand" .. prefix .. ((i + 1) % (nLines + 1))):GetValue()
		--local mbandPrev = SKIN:GetMeasure("mBand" .. prefix .. ((i + nLines) % (nLines + 1))):GetValue()

		local a = i
		if ClockWise then
			a = nLines - i + 1
		end

		if Smoothing > 0 then
			if i == 0 then
				mband0 = (mband0 + mbandNext) / 2
			elseif i == nLines then
				mband0 = (mband0 + mbandPrev) / 2
			else
				mband0 = (mband0 + mbandNext + mbandPrev) / 3
			end
		end
		
		if not completeCircle and (a == 1 or a == nLines) then
			mband0 = 0
		end

		local x0 = (Radius + ExtrudeMin + mband0 * (-Inward * 2 + 1) * (ExtrudeMax-ExtrudeMin)) *
			math.cos((AngleTotal - AngleTotal / NumOfItems * a + AngleStart) % PIx2) + Radius + ExtrudeMax
		local y0 = (RadiusY + ExtrudeMin + mband0 * (-Inward * 2 + 1) * (ExtrudeMax-ExtrudeMin)) *
			math.sin((AngleTotal - AngleTotal / NumOfItems * a + AngleStart) % PIx2) + Radius + ExtrudeMax

		table.insert(pts, x0)
		table.insert(pts, y0)
	end

	
	local path = ""
	
	local loopEnd = nLines
	if not completeCircle then loopEnd = nLines - 2 end
	
	for i = 1, loopEnd do
		-- lua tables start from index 1
		local num = (i - 1) * 2
		local x0 = pts[num + 1]
		local y0 = pts[num + 2]
		local x1 = pts[(num + 3 - 1) % #pts + 1]
		local y1 = pts[(num + 4 - 1) % #pts + 1]
		local x2 = pts[(num + 5 - 1) % #pts + 1]
		local y2 = pts[(num + 6 - 1) % #pts + 1]
		
		local sx = (x0 + x1) / 2
		local sy = (y0 + y1) / 2
		local ex = (x1 + x2) / 2
		local ey = (y1 + y2) / 2
	
		if not completeCircle and i == 1 then
			path = path .. x0 .. "," .. y0 .. " | LineTo " .. sx .. "," .. sy
		end
		
		if path == "" then path = path .. sx .. "," .. sy end
		path = path .. " | CurveTo " .. ex .. "," .. ey .. "," .. x1 .. "," .. y1
		
		if not completeCircle and i == nLines - 2 then
			path = path .. " | LineTo " .. x2 .. "," .. y2
		end
	end
	
	if WaveFilled then path = path .. " | ClosePath 1" end
	SKIN:Bang("!SetOption", "Wave" .. prefix, "Path", path)
end
