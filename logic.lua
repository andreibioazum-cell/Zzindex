local camera = { x = 10, y = 5, z = 10 }

function update(dt)
    -- Управление для тачскрина
    if IsMouseButtonDown(0) then
        camera.z = camera.z + 2 * dt
    end
end

function draw()
    -- Вызов отрисовки мира из C (через ffi или привязки)
    DrawText("FPS: "..GetFPS(), 10, 10, 20, BLACK)
end
