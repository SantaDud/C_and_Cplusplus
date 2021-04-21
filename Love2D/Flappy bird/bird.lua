bird = class{}

function bird:init()
	self.image = love.graphics.newImage('bird.png')
	self.width = self.image:getWidth()
	self.height = self.image:getHeight()
	self.x = vwidth/2-80
	self.y = vheight/2
	self.dy = 0
end

function bird:update(dt)	
	self.dy = self.dy + 20 * dt
	if love.keyboard.waspressed('space') then
		self.dy = -5
	end
	self.y = self.y + self.dy
end

function bird:render()
	love.graphics.draw(self.image, self.x, self.y)
end