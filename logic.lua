function update(dt)
    -- Если нажата кнопка мыши — ставим блок перед собой
    if is_mouse_pressed(0) then
        local x, y, z = get_target_block()
        setBlock(x, y, z, 1) -- 1 = Камень
    end
end
