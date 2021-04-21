push = require 'push'
class = require 'class'
require 'ball'
require 'paddle' 
width = 1920
height = 1080
vwidth = 800
vheight = 600
speed = 500
function love.load()
	
	love.window.setMode(vwidth, vheight, {vsync = true, fullscreen = false})
	love.window.setTitle('Pong')
	--love.graphics.setDefaultFilter('nearest', 'nearest')
	math.randomseed(os.time())
	sounds = {
		['paddle'] = love.audio.newSource('sounds/paddle.wav', 'static'),
		['wall'] = love.audio.newSource('sounds/wall.wav', 'static'),
		['score'] = love.audio.newSource('sounds/score.wav', 'static')
		}
	--push: setupScreen(vwidth, vheight, width, height, {vsync = true, fullscreen = false, resizable = true, canvas = false})
	paddle1 = paddle(10, vheight/2-2, 10, 55)
	paddle2 = paddle(vwidth-20, vheight/2-2, 10, 55)
	ball = ball(vwidth/2, vheight/2, 10, 10)
	score1 = 0
	score2 = 0
	state = 'start'
end
function love.update(dt)
	
	if state == 'play' then
		if love.keyboard.isDown('up') then
			paddle1: update0(dt, speed)
		elseif love.keyboard.isDown('down') then
			paddle1: update1(dt, speed, vheight)
		end
		paddle2.y = paddle2.y + ball.dy * dt
		if paddle2.y < 0 then
			paddle2.y = 0
		elseif paddle2.y > vheight-paddle2.height then
			paddle2.y = vheight-paddle2.height
		end
		--if love.keyboard.isDown('up') then
		--	paddle2: update0(dt, speed)
		--elseif love.keyboard.isDown('down') then
		--	paddle2: update1(dt, speed, vheight)
		--end
		if ball:collide(paddle1) then
			ball.x = ball.x + 5
			ball: change()
			sounds['paddle']:play()
		elseif ball:collide(paddle2) then
			ball.x = ball.x - 5
			ball: change()
			sounds['paddle']:play()
		end
		ball:update(dt, vheight)
		if ball.x > vwidth then
			sounds['score']:play()
			score1 = score1 + 1
			ball:reset(vwidth/2, vheight/2-2)
			ball.dx = -300
			state = 'serve'
		end
		if ball.x < 0 then
			score2 = score2 + 1
			sounds['score']:play()
			ball:reset(vwidth/2, vheight/2-2)
			ball.dx = 300
			state = 'serve'
		end
	elseif state == 'serve' then
		if ball.dx == 300 then
			a = 1
		elseif ball.dx == -300 then
			a = 2
		end
	end
	if score1 == 10 or score2 == 10 then
		state = 'end'
		if score1 == 10 then
			b = 1
		elseif score2 == 10 then
			b = 2
		end
	end
end

function love.keypressed(key)

	if key == 'return' then
		if state == 'start' or state == 'play' then
			state ='serve'
			ball: reset(vwidth/2, vheight/2-2)
		elseif state == 'serve' then
			state = 'play'
		elseif state == 'end' then
			state = 'start'
			score1 = 0
			score2 = 0
		end
	end
	if key == 'escape' then
		love.event.quit()
	end
end

function love.draw()

	--push: apply('start')
	--love.graphics.clear(40, 45, 52, 255)
	if state == 'start' then
		love.graphics.setFont(love.graphics.newFont(32))
		love.graphics.printf('Pong', 0, vheight/2-50, vwidth-10, 'center')
	elseif state == 'play' then
		love.graphics.setFont(love.graphics.newFont(30))
		love.graphics.printf(score2, vwidth/2, 25, vwidth/2, 'center')
		love.graphics.printf(score1, 0, 25, vwidth/2, 'center')
		paddle1: render()
		paddle2: render()
		ball:render()
	elseif state == 'serve' then
		if a == 1 then 
			love.graphics.setFont(love.graphics.newFont(20))
			love.graphics.printf('Player 1 is serving', 0, 25, vwidth, 'center')
			love.graphics.setFont(love.graphics.newFont(30))
			love.graphics.printf(score2, vwidth/2, 25, vwidth/2, 'center')
			love.graphics.printf(score1, 0, 25, vwidth/2, 'center')	
			paddle1: render()
			paddle2: render()
			ball:render()
		elseif a == 2 then
			love.graphics.setFont(love.graphics.newFont(20))
			love.graphics.printf('Player 2 is serving', 0, 25, vwidth, 'center')
			love.graphics.setFont(love.graphics.newFont(30))
			love.graphics.printf(score2, vwidth/2, 25, vwidth/2, 'center')
			love.graphics.printf(score1, 0, 25, vwidth/2, 'center')	
			paddle1: render()
			paddle2: render()
			ball:render()
		end
	elseif state == 'end' then
		if b == 1 then
			love.graphics.setFont(love.graphics.newFont(50))
			love.graphics.printf('Player 1 Wins', 0, vheight/2-50, vwidth, 'center')
			love.graphics.setFont(love.graphics.newFont(30))
			love.graphics.printf(score2, vwidth/2, 25, vwidth/2, 'center')
			love.graphics.printf(score1, 0, 25, vwidth/2, 'center')	
			paddle1: render()
			paddle2: render()
			ball:render()
		elseif b == 2 then
			love.graphics.setFont(love.graphics.newFont(50))
			love.graphics.printf('Player 2 Wins', 0, vheight/2-50, vwidth, 'center')
			love.graphics.setFont(love.graphics.newFont(30))
			love.graphics.printf(score2, vwidth/2, 25, vwidth/2, 'center')
			love.graphics.printf(score1, 0, 25, vwidth/2, 'center')	
			paddle1: render()
			paddle2: render()
			ball:render()
		end
	end
	--push: apply('end')
end