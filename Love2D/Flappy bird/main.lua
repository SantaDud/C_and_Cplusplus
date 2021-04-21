push = require 'push'
class = require 'class'

require 'bird'
require 'Pipe'
require 'PipePair'

width = 1280
height = 720
vwidth = 512
vheight = 288

background = love.graphics.newImage('background.png')
ground = love.graphics.newImage('ground.png')

math.randomseed(os.time())
speed = 50
loop = 413
timer = 0

local lastY = -pipeheight + math.random(80) + 20

function love.load()
	love.graphics.setDefaultFilter('nearest', 'nearest')
	push:setupScreen(vwidth, vheight, width, height, 
	{
		fullscreen = false, 
		vsync = true, 
		resizable = true
	})
	
	love.window.setTitle('Flappy Bird')
	groundscroll = 0
	backgroundscroll = 0
	
	pipepair = {}
	love.keyboard.keyspressed = {}

	bird = bird()
end

function love.resize(w,h)
	push:resize(w,h)
end

function love.keypressed(key)
	love.keyboard.keyspressed[key] = true
	if key == 'escape' then
		love.event.quit()
	end
end

function love.keyboard.waspressed(key)
	if love.keyboard.keyspressed[key] then
		return true
	else 
		return false
	end
end

function love.update(dt)
	backgroundscroll = (backgroundscroll + 30 * dt) % loop
	groundscroll = (groundscroll + speed * dt) % vwidth
	timer = timer + dt
	if timer > 2 then

		local y = math.max(-pipeheight + 10, 
            math.min(lastY + math.random(-20, 20), vheight - 90 - pipeheight))
        lastY = y

		table.insert(pipepair, PipePair(y))
		timer = 0
	end

	bird:update(dt)
	
	for k, pipe in pairs(pipepair) do
		PipePair:update(dt)
		
		if PipePair.remove then
			table.remove(pipepair, k)
		end
	
	end

	love.keyboard.keyspressed = {}
end

function love.draw()
	push:start()
	love.graphics.draw(background, -backgroundscroll, 0)

for k, pipe in pairs(pipepair) do
	PipePair:render()
end

	love.graphics.draw(ground, -groundscroll, vheight-10)
	bird:render()
	push:finish()
end