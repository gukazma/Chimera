/*
 * @Author       : gukazma && gukazma@proton.me
 * @Date         : 2023-07-20 21:50:20
 * @FilePath     : \Chimera\Modules\Graphics\Vulkan\Sources\Chimera\Vulkan\Device.cpp
 * @Description  :
 * MIT License
 *
 * Copyright (c) 2023 gukazma
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files, to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 */
#include <Chimera/Vulkan/Device.h>
namespace Chimera {
namespace Vulkan {
Device::Device(vk::Device& device_)
    : m_nativeDevice(device_)
{}
}   // namespace Vulkan
}   // namespace Chimera
