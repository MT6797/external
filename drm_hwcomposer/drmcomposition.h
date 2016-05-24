/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_DRM_COMPOSITION_H_
#define ANDROID_DRM_COMPOSITION_H_

#include "compositor.h"
#include "drm_hwcomposer.h"
#include "drmdisplaycomposition.h"
#include "drmplane.h"
#include "importer.h"

#include <deque>
#include <map>
#include <vector>

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

namespace android {

class DrmComposition : public Composition {
 public:
  DrmComposition(DrmResources *drm, Importer *importer);
  ~DrmComposition();

  virtual int Init();

  virtual unsigned GetRemainingLayers(int display, unsigned num_needed) const;
  virtual int AddLayer(int display, hwc_layer_1_t *layer, hwc_drm_bo_t *bo);
  int AddDpmsMode(int display, uint32_t dpms_mode);

  std::unique_ptr<DrmDisplayComposition> TakeDisplayComposition(int display);

 private:
  DrmComposition(const DrmComposition &) = delete;

  DrmResources *drm_;
  Importer *importer_;

  std::vector<DrmPlane *> primary_planes_;
  std::deque<DrmPlane *> overlay_planes_;

  /*
   * This _must_ be read-only after it's passed to QueueComposition. Otherwise
   * locking is required to maintain consistency across the compositor threads.
   */
  std::map<int, std::unique_ptr<DrmDisplayComposition>> composition_map_;
};

}

#endif  // ANDROID_DRM_COMPOSITION_H_
