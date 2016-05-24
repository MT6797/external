#
# Copyright (C) 2014 MediaTek Inc.
# Modification based on code covered by the mentioned copyright
# and/or permission notice(s).
#
# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This file simply inherits from all the know language packs.
ifeq ($(strip $(MTK_GMO_ROM_OPTIMIZE)),yes)
#$(call inherit-product, external/svox/pico/lang/PicoLangDeDeInSystem.mk)
#$(call inherit-product, external/svox/pico/lang/PicoLangEnGBInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangEnUsInSystem.mk)
#$(call inherit-product, external/svox/pico/lang/PicoLangEsEsInSystem.mk)
#$(call inherit-product, external/svox/pico/lang/PicoLangFrFrInSystem.mk)
#$(call inherit-product, external/svox/pico/lang/PicoLangItItInSystem.mk)
else
$(call inherit-product, external/svox/pico/lang/PicoLangDeDeInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangEnGBInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangEnUsInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangEsEsInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangFrFrInSystem.mk)
$(call inherit-product, external/svox/pico/lang/PicoLangItItInSystem.mk)
endif
