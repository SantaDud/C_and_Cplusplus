paddle = class{}

function paddle: init(x, y, width, height)
	self.x = x
	self.y = y
	self.width = width
	self.height = height
end

function paddle: reset(y)
	self.y = y
end

function paddle: render()
	love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end

function paddle: update0(dt, speed)
	self.y = math.max(0, self.y + -speed * dt)
end
function paddle: update1(dt, speed, vheight)
	self.y = math.min(vheight - self.height, self.y + speed * dt)
end
