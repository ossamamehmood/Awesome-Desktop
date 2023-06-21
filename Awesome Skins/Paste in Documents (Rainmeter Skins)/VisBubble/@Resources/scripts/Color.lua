function math.lerp(a, b, t)
	return a + (b - a) * t
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

	local color = SKIN:ReplaceVariables(SELF:GetOption("Color", "FFFFFF"))
	local num = SKIN:ParseFormula(SELF:GetOption("NumOfItems", "0"))
	local prefix = SELF:GetOption("Prefix")

	if color:match("|") == nil then return end

	local table = {}

	for v in string.gmatch(color, '[^|]+') do
		local v,p = v:match("([^:]+)[%s]*[:]?[%s]*([^%s]*)")
		local r,g,b,a = parseColor(v)

		if p ~= "" then p = SKIN:ParseFormula(p) end

		table[#table + 1] = { ["r"]=r, ["b"]=b, ["g"]=g, ["a"]=a, ["p"]=p }
	end

	if table[1]["p"] == "" then table[1]["p"] = 0 end
	if table[#table]["p"] == "" then table[#table]["p"] = 100 end
	for i=2,#table-1,1 do
		if table[i]["p"] == "" then
			table[i]["p"] = 100 / (#table - 1) * (i - 1)
		end
	end

	for i=0,num-1,1 do
		local pct = i / (num - 1) * 100

		local a = table[1]
		local b = nil

		if pct <= a["p"] then
			b = a
		else
			for j=2,#table,1 do
				if pct <= table[j]["p"] then
					b = table[j]
					break
				end
				a = table[j]
			end
		end

		if b == nil then b = a end

		if b == a then
			pct = 1
		else
			pct = (pct - a["p"]) / (b["p"] - a["p"])
		end

		local cr = math.lerp(a["r"], b["r"], pct)
		local cg = math.lerp(a["g"], b["g"], pct)
		local cb = math.lerp(a["b"], b["b"], pct)
		local ca = math.lerp(a["a"], b["a"], pct)

		SKIN:Bang("!SetOption", prefix .. i, "LineColor", cr .. "," .. cg .. "," .. cb .. "," .. ca)
	end

end
