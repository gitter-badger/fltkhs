{-# LANGUAGE CPP, TypeSynonymInstances, FlexibleInstances, MultiParamTypeClasses, FlexibleContexts #-}
{-# OPTIONS_GHC -fno-warn-orphans #-}
module Graphics.UI.FLTK.LowLevel.Fl_Fill_Slider
    (
     fillSliderNew
    )
where
#include "Fl_ExportMacros.h"
#include "Fl_Types.h"
#include "Fl_SliderC.h"
import C2HS hiding (cFromEnum, cFromBool, cToBool,cToEnum)
import Foreign.C.Types
import Graphics.UI.FLTK.LowLevel.Fl_Types
import Graphics.UI.FLTK.LowLevel.Utils
import Graphics.UI.FLTK.LowLevel.Hierarchy

{# fun Fl_Fill_Slider_New as fillSliderNew' { `Int',`Int',`Int',`Int' } -> `Ptr ()' id #}
{# fun Fl_Fill_Slider_New_WithLabel as fillSliderNewWithLabel' { `Int',`Int',`Int',`Int',`String'} -> `Ptr ()' id #}
fillSliderNew :: Rectangle -> Maybe String -> IO (Ref FillSlider)
fillSliderNew rectangle l' =
    let (x_pos, y_pos, width, height) = fromRectangle rectangle
    in case l' of
        Nothing -> fillSliderNew' x_pos y_pos width height >>=
                             toRef
        Just l -> fillSliderNewWithLabel' x_pos y_pos width height l >>=
                             toRef