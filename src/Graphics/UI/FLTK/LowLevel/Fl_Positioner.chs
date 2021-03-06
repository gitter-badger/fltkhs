{-# LANGUAGE CPP, ExistentialQuantification, TypeSynonymInstances, FlexibleInstances, MultiParamTypeClasses, FlexibleContexts, ScopedTypeVariables #-}
{-# OPTIONS_GHC -fno-warn-orphans #-}
module Graphics.UI.FLTK.LowLevel.Fl_Positioner
    (
     -- * Constructor
     positionerNew
    )
where
#include "Fl_ExportMacros.h"
#include "Fl_Types.h"
#include "Fl_PositionerC.h"
import C2HS hiding (cFromEnum, cFromBool, cToBool,cToEnum)
import Foreign.C.Types
import Graphics.UI.FLTK.LowLevel.Fl_Enumerations
import Graphics.UI.FLTK.LowLevel.Fl_Types
import Graphics.UI.FLTK.LowLevel.Utils
import Graphics.UI.FLTK.LowLevel.Hierarchy
import Graphics.UI.FLTK.LowLevel.Dispatch

{# fun Fl_Positioner_New as positionerNew' { `Int',`Int',`Int',`Int' } -> `Ptr ()' id #}
{# fun Fl_Positioner_New_WithLabel as positionerNewWithLabel' { `Int',`Int',`Int',`Int',`String'} -> `Ptr ()' id #}
positionerNew :: Rectangle -> Maybe String -> IO (Ref Positioner)
positionerNew rectangle l'=
    let (x_pos, y_pos, width, height) = fromRectangle rectangle
    in case l' of
        Nothing -> positionerNew' x_pos y_pos width height >>=
                             toRef
        Just l -> positionerNewWithLabel' x_pos y_pos width height l >>=
                               toRef

{# fun Fl_Positioner_Destroy as positionerDestroy' { id `Ptr ()' } -> `()' supressWarningAboutRes #}
instance (impl ~ (IO ())) => Op (Destroy ()) Positioner orig impl where
  runOp _ _ win = swapRef win $ \winPtr -> do
    positionerDestroy' winPtr
    return nullPtr

{#fun Fl_Positioner_handle as positionerHandle' { id `Ptr ()', id `CInt' } -> `Int' #}
instance (impl ~ (Event -> IO Int)) => Op (Handle ()) Positioner orig impl where
  runOp _ _ positioner event = withRef positioner (\p -> positionerHandle' p (fromIntegral . fromEnum $ event))
{# fun unsafe Fl_Positioner_set_xvalue as setXvalue' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetXvalue ()) Positioner orig impl where
  runOp _ _ positioner xvalue = withRef positioner $ \positionerPtr -> setXvalue' positionerPtr xvalue
{# fun unsafe Fl_Positioner_xvalue as xvalue' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetXvalue ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> xvalue' positionerPtr
{# fun unsafe Fl_Positioner_set_yvalue as setYvalue' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetYvalue ()) Positioner orig impl where
  runOp _ _ positioner yvalue = withRef positioner $ \positionerPtr -> setYvalue' positionerPtr yvalue
{# fun unsafe Fl_Positioner_yvalue as yvalue' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetYvalue ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> yvalue' positionerPtr
{# fun unsafe Fl_Positioner_set_xminimum as setXminimum' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetXminimum ()) Positioner orig impl where
  runOp _ _ positioner xminimum = withRef positioner $ \positionerPtr -> setXminimum' positionerPtr xminimum
{# fun unsafe Fl_Positioner_xminimum as xminimum' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetXminimum ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> xminimum' positionerPtr
{# fun unsafe Fl_Positioner_set_yminimum as setYminimum' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetYminimum ()) Positioner orig impl where
  runOp _ _ positioner yminimum = withRef positioner $ \positionerPtr -> setYminimum' positionerPtr yminimum
{# fun unsafe Fl_Positioner_yminimum as yminimum' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetYminimum ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> yminimum' positionerPtr
{# fun unsafe Fl_Positioner_set_xmaximum as setXmaximum' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetXmaximum ()) Positioner orig impl where
  runOp _ _ positioner xmaximum = withRef positioner $ \positionerPtr -> setXmaximum' positionerPtr xmaximum
{# fun unsafe Fl_Positioner_xmaximum as xmaximum' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetXmaximum ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> xmaximum' positionerPtr
{# fun unsafe Fl_Positioner_set_ymaximum as setYmaximum' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetYmaximum ()) Positioner orig impl where
  runOp _ _ positioner ymaximum = withRef positioner $ \positionerPtr -> setYmaximum' positionerPtr ymaximum
{# fun unsafe Fl_Positioner_ymaximum as ymaximum' { id `Ptr ()' } -> `Double' #}
instance (impl ~ ( IO (Double))) => Op (GetYmaximum ()) Positioner orig impl where
  runOp _ _ positioner = withRef positioner $ \positionerPtr -> ymaximum' positionerPtr
{# fun unsafe Fl_Positioner_xbounds as xbounds' { id `Ptr ()',`Double',`Double' } -> `()' #}
instance (impl ~ (Double -> Double ->  IO ())) => Op (SetXbounds ()) Positioner orig impl where
  runOp _ _ positioner xstart xend = withRef positioner $ \positionerPtr -> xbounds' positionerPtr xstart xend
{# fun unsafe Fl_Positioner_ybounds as ybounds' { id `Ptr ()',`Double',`Double' } -> `()' #}
instance (impl ~ (Double -> Double ->  IO ())) => Op (SetYbounds ()) Positioner orig impl where
  runOp _ _ positioner ystart yend = withRef positioner $ \positionerPtr -> ybounds' positionerPtr ystart yend
{# fun unsafe Fl_Positioner_xstep as xstep' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetXstep ()) Positioner orig impl where
  runOp _ _ positioner xstep = withRef positioner $ \positionerPtr -> xstep' positionerPtr xstep
{# fun unsafe Fl_Positioner_ystep as ystep' { id `Ptr ()',`Double' } -> `()' #}
instance (impl ~ (Double ->  IO ())) => Op (SetYstep ()) Positioner orig impl where
  runOp _ _ positioner ystep = withRef positioner $ \positionerPtr -> ystep' positionerPtr ystep
