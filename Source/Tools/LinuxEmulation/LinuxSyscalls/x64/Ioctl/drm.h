#pragma once

#include <FEXCore/Utils/CompilerDefs.h>

#include "LinuxSyscalls/x64/Types.h"
#include "LinuxSyscalls/x64/Ioctl/HelperDefines.h"

#include <cstdint>
extern "C" {
#include <drm/drm.h>
#include <drm/drm_mode.h>
#include <drm/i915_drm.h>
#include <drm/amdgpu_drm.h>
#include <drm/lima_drm.h>
#include <drm/panfrost_drm.h>
#include <drm/msm_drm.h>
#include <drm/nouveau_drm.h>
#include <drm/vc4_drm.h>
#include <drm/v3d_drm.h>
#include <drm/virtgpu_drm.h>
}
#include <sys/ioctl.h>

#define CPYT(x) val.x = x
#define CPYF(x) x = val.x
namespace FEX::HLE::x64 {

#include "LinuxSyscalls/x64/Ioctl/drm.inl"
#include "LinuxSyscalls/x64/Ioctl/amdgpu_drm.inl"
#include "LinuxSyscalls/x64/Ioctl/msm_drm.inl"

} // namespace FEX::HLE::x64
#undef CPYT
#undef CPYF
