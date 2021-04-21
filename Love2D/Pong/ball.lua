ball = class{}

function ball: init(x, y, width, height)
	self.x = x
	self.y = y
	self.width = width
	self.height = height
	self.dx = math.random(2) == 1 and 300 or -300
	self.dy = math.random(400, -400) 
end

function ball: update(dt, height)

	self.x = self.x + self.dx * dt
	self.y = self.y + self.dy * dt
	if self.y <=0  then
		sounds['wall']:play()
		self.y = 0
		self.dy = -self.dy	
	end
	if self.y >= vheight then
		sounds['wall']:play()
		self.y = vheight - 10
		self.dy = -self.dy
	end
end

function ball: reset(x, y)
	self.x = x
	self.y = y
	self.dx = math.random(2) == 1 and 300 or -300
	self.dy = math.random(400, -400)
end

function ball: render()
	love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end

function ball: collide(paddle)
	if self.x > paddle.x + paddle.width or self.x + self.width < paddle.x then
		return false
	end
	if self.y > paddle.y + paddle.height or self.y + self.height < paddle.y then
		return false
	end
	return true
end
function ball: change()
	self.dx = -self.dx * 1.03
	if self.dy < 0 then
		self.dy = -math.random(100, 400)
	else
		self.dy = math.random(100, 400) 
	end	
end