{-# LANGUAGE CPP, ExistentialQuantification, TypeSynonymInstances, FlexibleInstances, MultiParamTypeClasses, FlexibleContexts, ScopedTypeVariables #-}
{-# OPTIONS_GHC -fno-warn-orphans #-}
module Graphics.UI.FLTK.LowLevel.Fl_Bitmap
 (
  bitmapNew
 )
where
#include "Fl_ExportMacros.h"
#include "Fl_Types.h"
#include "Fl_BitmapC.h"
import C2HS hiding (cFromEnum, cFromBool, cToBool,cToEnum)
import Foreign.C.Types
import Graphics.UI.FLTK.LowLevel.Fl_Enumerations
import Graphics.UI.FLTK.LowLevel.Fl_Types
import Graphics.UI.FLTK.LowLevel.Utils
import Graphics.UI.FLTK.LowLevel.Hierarchy
import Graphics.UI.FLTK.LowLevel.Dispatch

{# fun unsafe Fl_Bitmap_New as flBitmapNew' { id `Ptr CChar',`Int',`Int' } -> `Ptr ()' id #}
bitmapNew :: BitmapHs -> IO (Ref Bitmap)
bitmapNew bitmap = withBitmap bitmap (\ptr width' height' -> flBitmapNew' ptr width' height' >>= toRef)
{# fun unsafe Fl_Bitmap_Destroy as flBitmapDestroy' { id `Ptr ()' } -> `()' id #}
instance (impl ~ (IO ())) => Op (Destroy ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> flBitmapDestroy' bitmapPtr
{# fun unsafe Fl_Bitmap_w as w' { id `Ptr ()' } -> `Int' #}
instance (impl ~ ( IO (Int))) => Op (GetW ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> w' bitmapPtr
{# fun unsafe Fl_Bitmap_h as h' { id `Ptr ()' } -> `Int' #}
instance (impl ~ ( IO (Int))) => Op (GetH ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> h' bitmapPtr
{# fun unsafe Fl_Bitmap_d as d' { id `Ptr ()' } -> `Int' #}
instance (impl ~ ( IO (Int))) => Op (GetD ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> d' bitmapPtr
{# fun unsafe Fl_Bitmap_ld as ld' { id `Ptr ()' } -> `Int' #}
instance (impl ~ ( IO (Int))) => Op (GetLd ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> ld' bitmapPtr
{# fun unsafe Fl_Bitmap_count as count' { id `Ptr ()' } -> `Int' #}
instance (impl ~ ( IO (Int))) => Op (GetCount ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> count' bitmapPtr
{# fun unsafe Fl_Bitmap_copy_with_w_h as copyWithWH' { id `Ptr ()',`Int',`Int' } -> `Ptr ()' id #}
{# fun unsafe Fl_Bitmap_copy as copy' { id `Ptr ()' } -> `Ptr ()' id #}
instance (impl ~ ( Maybe Size -> IO (Ref Bitmap))) => Op (Copy ()) Bitmap orig impl where
  runOp _ _ bitmap size' = case size' of
    Just (Size (Width w) (Height h)) -> withRef bitmap $ \bitmapPtr -> copyWithWH' bitmapPtr w h >>= toRef
    Nothing -> withRef bitmap $ \bitmapPtr -> copy' bitmapPtr >>= toRef
{# fun unsafe Fl_Bitmap_color_average as colorAverage' { id `Ptr ()',cFromColor `Color',`Float' } -> `()' #}
instance (impl ~ (Color -> Float ->  IO ())) => Op (ColorAverage ()) Bitmap orig impl where
  runOp _ _ bitmap c i = withRef bitmap $ \bitmapPtr -> colorAverage' bitmapPtr c i
{# fun unsafe Fl_Bitmap_inactive as inactive' { id `Ptr ()' } -> `()' #}
instance (impl ~ ( IO ())) => Op (Inactive ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> inactive' bitmapPtr
{# fun unsafe Fl_Bitmap_desaturate as desaturate' { id `Ptr ()' } -> `()' #}
instance (impl ~ ( IO ())) => Op (Desaturate ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> desaturate' bitmapPtr

{# fun unsafe Fl_Bitmap_draw_with_cx_cy as drawWithCxCy' { id `Ptr ()',`Int',`Int',`Int',`Int',`Int',`Int' } -> `()' #}
{# fun unsafe Fl_Bitmap_draw_with_cx as drawWithCx' { id `Ptr ()',`Int',`Int',`Int',`Int',`Int' } -> `()' #}
{# fun unsafe Fl_Bitmap_draw_with_cy as drawWithCy' { id `Ptr ()',`Int',`Int',`Int',`Int',`Int' } -> `()' #}
{# fun unsafe Fl_Bitmap_draw_with as drawWith' { id `Ptr ()',`Int',`Int',`Int',`Int' } -> `()' #}
instance (impl ~ (Position -> Size -> Maybe X -> Maybe Y -> IO ())) => Op (DrawResize ()) Bitmap orig impl where
  runOp _ _ bitmap (Position (X x) (Y y)) (Size (Width w) (Height h)) xOffset yOffset =
    case (xOffset, yOffset) of
      (Just (X xOff), Just (Y yOff)) ->
        withRef bitmap $ \bitmapPtr -> drawWithCxCy' bitmapPtr x y w h (fromIntegral xOff) (fromIntegral yOff)
      (Just (X xOff), Nothing) ->
        withRef bitmap $ \bitmapPtr -> drawWithCx' bitmapPtr x y w h (fromIntegral xOff)
      (Nothing, Just (Y yOff)) ->
        withRef bitmap $ \bitmapPtr -> drawWithCy' bitmapPtr x y w h (fromIntegral yOff)
      (Nothing, Nothing) ->
        withRef bitmap $ \bitmapPtr -> drawWith' bitmapPtr x y w h

{# fun unsafe Fl_Bitmap_draw as draw' { id `Ptr ()',`Int',`Int' } -> `()' #}
instance (impl ~ (Position ->  IO ())) => Op (Draw ()) Bitmap orig impl where
  runOp _ _ image (Position (X x_pos') (Y y_pos')) = withRef image $ \imagePtr -> draw' imagePtr x_pos' y_pos'
{# fun unsafe Fl_Bitmap_uncache as uncache' { id `Ptr ()' } -> `()' #}
instance (impl ~ ( IO ())) => Op (Uncache ()) Bitmap orig impl where
  runOp _ _ bitmap = withRef bitmap $ \bitmapPtr -> uncache' bitmapPtr
