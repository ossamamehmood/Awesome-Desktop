function math.clamp(value, lower, upper)
	return math.min(math.max(value, lower), upper)
end

function hsvToRgb(h, s, v)
  local r, g, b

  local i = math.floor(h * 6);
  local f = h * 6 - i;
  local p = v * (1 - s);
  local q = v * (1 - f * s);
  local t = v * (1 - (1 - f) * s);

  i = i % 6

  if i == 0 then r, g, b = v, t, p
  elseif i == 1 then r, g, b = q, v, p
  elseif i == 2 then r, g, b = p, v, t
  elseif i == 3 then r, g, b = p, q, v
  elseif i == 4 then r, g, b = t, p, v
  elseif i == 5 then r, g, b = v, p, q
  end

  return math.floor(r * 255), math.floor(g * 255), math.floor(b * 255)
end

function rgbToHsv(r, g, b)
  r, g, b = r / 255, g / 255, b / 255
  local max, min = math.max(r, g, b), math.min(r, g, b)
  local h, s, v
  v = max

  local d = max - min
  if max == 0 then s = 0 else s = d / max end

  if max == min then
    h = 0 -- achromatic
  else
    if max == r then
    h = (g - b) / d
    if g < b then h = h + 6 end
    elseif max == g then h = (b - r) / d + 2
    elseif max == b then h = (r - g) / d + 4
    end
    h = h / 6
  end

  return h, s, v
end

function parseColor(v)
	local r,g,b,a = 255,255,255,255

	local hexRgb = v:match("^[%s]*%x%x%x%x%x%x")

	if hexRgb ~= nil then
		r,g,b = hexRgb:match("(%x%x)(%x%x)(%x%x)")
		a = v:sub(7)
		if a:len() ~= 2 then a = "FF" end
		r = tonumber(r, 16)
		g = tonumber(g, 16)
		b = tonumber(b, 16)
		a = tonumber(a, 16)
	else
		r,g,b,a = v:match("^[%s]*([^,]+)[%s]*,[%s]*([^,]+)[%s]*,[%s]*([^,]+)[%s]*[,]?[%s]*([^%s]*)")
		if a == "" then a = 255 end
		r = SKIN:ParseFormula(r)
		g = SKIN:ParseFormula(g)
		b = SKIN:ParseFormula(b)
		a = SKIN:ParseFormula(a)
	end

	return r,g,b,a
end

function Initialize()
	firstClick = true

	update = true
	local col = SKIN:GetVariable("Color")
	if col == "" then
		update = false
		return
	end

	SKIN:Bang("!Draggable", "0")
	callback = SKIN:GetVariable("Callback")

	local r,g,b,a = parseColor(col)
	SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)

	local h,s,v = rgbToHsv(r,g,b)
	curH = h
	curS = s
	curV = v
	curA = a

	r,g,b = hsvToRgb(h, s, 1)

	SKIN:Bang("!SetVariable", "ValColor", r .. "," .. g .. "," .. b)

end

function resolve(x, y, a)
	if not update then return end

	x = x - SKIN:GetVariable("CURRENTCONFIGX")
	y = y - SKIN:GetVariable("CURRENTCONFIGY")

	if x < 0 or y < 0 or x > 288 or y > 160 then
		if a == 1 then
			if firstClick then
				firstClick = false
			else
				update = false
				SKIN:Bang("!Hide")
				firstClick = true
			end
			return
		end
	end

	if a == 1 then click(x, y) elseif a == 2 then drag(x, y) else release(x, y) end

	firstClick = false
	SKIN:Bang("!Update")
	SKIN:Bang("!Redraw")
end

function click(x, y)
	if x <= 256 and y <= 128 then
		curH = x / 256
		curS = 1 - y / 128
		local r,g,b = hsvToRgb(curH, curS, 1)
		SKIN:Bang("!SetVariable", "ValColor", r .. "," .. g .. "," .. b)
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
		focus = "hs"
	elseif x > 256 and y <= 128 then
		curV = 1 - y / 128
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
		focus = "v"
	elseif x < 176 and y > 128 then
		curA = 255 - x / 176 * 255
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
		focus = "a"
	elseif x < 232 and y > 128 then
		local r,g,b,a = parseColor(SKIN:GetVariable("OldColor"))
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		local h,s,v = rgbToHsv(r,g,b)
		curH = h
		curS = s
		curV = v
		curA = a
		r,g,b = hsvToRgb(h, s, 1)
		SKIN:Bang("!SetVariable", "ValColor", r .. "," .. g .. "," .. b)
	else
		local bang = callback:gsub("%%color%%", SKIN:GetVariable("Color"))
		SKIN:Bang(bang)
		update = false
		SKIN:Bang("!Hide")
	end
end

function drag(x, y)
	if focus == "hs" then
		x = math.clamp(x, 0, 256)
		y = math.clamp(y, 0, 128)
		curH = x / 256
		curS = 1 - y / 128
		local r,g,b = hsvToRgb(curH, curS, 1)
		SKIN:Bang("!SetVariable", "ValColor", r .. "," .. g .. "," .. b)
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
	elseif focus == "v" then
		y = math.clamp(y, 0, 128)
		curV = 1 - y / 128
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
	elseif focus == "a" then
		x = math.clamp(x, 0, 176)
		curA = 255 - x / 176 * 255
		r,g,b = hsvToRgb(curH, curS, curV)
		SKIN:Bang("!SetVariable", "OpaqueColor", r .. "," .. g .. "," .. b)
		SKIN:Bang("!SetVariable", "Color", r .. "," .. g .. "," .. b .. "," .. curA)
		focus = "a"
	end
end

function release(x, y)
	focus = nil
end
