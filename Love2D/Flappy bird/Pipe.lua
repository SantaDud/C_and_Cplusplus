Pipe = class{}

pipewidth = 70
pipeheight = 430
scroll = 50

local pipe_image = love.graphics.newImage('pipe.png')

function Pipe:init(orientation, y)
    
    self.x = vwidth
    self.orientation = orientation
    self.y = y

end

function Pipe:update(dt)
end

function Pipe:render()
    love.graphics.draw(pipe_image, self.x,
    (self.orientation == 'top' and self.y + pipeheight or self.y), 0, 1, 
    (self.orientation == 'top' and -1 or 1))
end