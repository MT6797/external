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

#ifndef ANDROID_DRM_COMPOSITOR_H_
#define ANDROID_DRM_COMPOSITOR_H_

#include "compositor.h"
#include "drmdisplaycompositor.h"
#include "importer.h"

#include <map>
#include <sstream>

namespace android {

class DrmCompositor : public Compositor {
 public:
  DrmCompositor(DrmResources *drm);
  ~DrmCompositor();

  virtual int Init();

  virtual Targeting *targeting() {
    return NULL;
  }

  virtual Composition *CreateComposition(Importer *importer);

  virtual int QueueComposition(Composition *composition);
  virtual int Composite();
  virtual void Dump(std::ostringstream *out) const;

 private:
  DrmCompositor(const DrmCompositor &) = delete;

  DrmResources *drm_;

  // mutable for Dump() propagation
  mutable std::map<int, DrmDisplayCompositor> compositor_map_;
};
}

#endif  // ANDROID_DRM_COMPOSITOR_H_
