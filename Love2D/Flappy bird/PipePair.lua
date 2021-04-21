PipePair = class{}


local gapHeight = math.random(80, 100)

function PipePair:init(y)

    self.x = 512
    self.y = y

    self.pipes = {
        ['upper'] = Pipe('top', self.y),
        ['lower'] = Pipe('bottom', self.y + pipeheight + gapHeight)
    }

    self.remove = false
end

function PipePair:update(dt)
    
        self.x = self.x - scroll * dt
        self.pipes['lower'].x = self.x
        self.pipes['upper'].x = self.x
    if not self.x > -pipewidth then
        self.remove = true
    end
    --[[self.pipes['lower'] = Pipe:update(dt)
    self.pipes['upper'] = Pipe:update(dt)

    if self.x < -pipewidth then
        self.remove = true
    end
--]]
end

function PipePair:render()

    self.pipes['lower'] = Pipe:render()
    self.pipes['upper'] = Pipe:render()

end