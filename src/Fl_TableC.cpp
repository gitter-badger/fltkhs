#include "Fl_TableC.h"
#ifdef __cplusplus
class Fl_DerivedTable : public Fl_Table {
  fl_Table_Virtual_Funcs* overriddenFuncs;
public:
  Fl_DerivedTable(int X, int Y, int W, int H, const char *l, fl_Table_Virtual_Funcs* funcs) : Fl_Table(X,Y,W,H,l){
    overriddenFuncs = funcs;
  }
  Fl_DerivedTable(int X, int Y, int W, int H, fl_Table_Virtual_Funcs* funcs):Fl_Table(X,Y,W,0){
    overriddenFuncs = funcs;
  }
  ~Fl_DerivedTable();
  void draw_cell(TableContext tableContext, int R, int C, int X, int Y, int W, int H){
    TableContextC c = (TableContextC)-1;
    switch(tableContext){
    case Fl_Table::CONTEXT_NONE:      {c = CONTEXT_NONEC;      break;}
    case Fl_Table::CONTEXT_STARTPAGE: {c = CONTEXT_STARTPAGEC; break;}
    case Fl_Table::CONTEXT_ENDPAGE:   {c = CONTEXT_ENDPAGEC;   break;}
    case Fl_Table::CONTEXT_ROW_HEADER:{c = CONTEXT_ROW_HEADERC;break;}
    case Fl_Table::CONTEXT_COL_HEADER:{c = CONTEXT_COL_HEADERC;break;}
    case Fl_Table::CONTEXT_CELL:      {c = CONTEXT_CELLC;      break;}
    case Fl_Table::CONTEXT_TABLE:     {c = CONTEXT_TABLEC;     break;}
    case Fl_Table::CONTEXT_RC_RESIZE: {c = CONTEXT_RC_RESIZEC; break;}
    default:                          {c = TableContextC(-1);  break;}
    }
    this->overriddenFuncs->fl_Table_draw_cell(c,R,C,X,Y,W,H);
  }
  void clear(){
    if (this->overriddenFuncs->fl_Table_clear != NULL) {
      this->overriddenFuncs->fl_Table_clear();
    }
    else {
      Fl_Table::clear(); 
    }
  }
  void rows(int val){
    this->overriddenFuncs->fl_Table_rows(val);
  }
  void cols(int val){
    this->overriddenFuncs->fl_Table_cols(val);
  }
};
EXPORT {
#endif
  FL_EXPORT_C(fl_Table_Virtual_Funcs*, Fl_Table_default_virtual_funcs)(){
    fl_Table_Virtual_Funcs ref = {NULL,NULL,NULL,NULL};
    fl_Table_Virtual_Funcs* ptr = &ref;
    return ptr;
  }
  FL_EXPORT_C(fl_Group,Fl_Table_parent)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->parent();
  }
  FL_EXPORT_C(void,Fl_Table_set_parent)(fl_Table table,fl_Group grp){
    (static_cast<Fl_Table*>(table))->parent((static_cast<Fl_Group*>(grp)));
  }
  FL_EXPORT_C(uchar,Fl_Table_type)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->type();
  }
  FL_EXPORT_C(void,Fl_Table_set_type)(fl_Table table,uchar t){
    (static_cast<Fl_Table*>(table))->type(t);
  }
  FL_EXPORT_C(int,Fl_Table_x)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->x();
  }
  FL_EXPORT_C(int,Fl_Table_y)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->y();
  }
  FL_EXPORT_C(int,Fl_Table_w)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->w();
  }
  FL_EXPORT_C(int,Fl_Table_h)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->h();
  }
  FL_EXPORT_C(Fl_Align,Fl_Table_align)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->align();
  }
  FL_EXPORT_C(Fl_Boxtype,Fl_Table_box)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->box();
  }
  FL_EXPORT_C(void,Fl_Table_set_box)(fl_Table table,Fl_Boxtype new_box){
    (static_cast<Fl_Table*>(table))->box((static_cast<Fl_Boxtype>(new_box)));
  }
  FL_EXPORT_C(Fl_Color,Fl_Table_color)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->color();
  }
  FL_EXPORT_C(void,Fl_Table_set_color)(fl_Table table,Fl_Color bg){
    (static_cast<Fl_Table*>(table))->color(bg);
  }
  FL_EXPORT_C(void,Fl_Table_set_background_and_selection_color)(fl_Table table,Fl_Color bg,Fl_Color a){
    (static_cast<Fl_Table*>(table))->color(bg,a);
  }
  FL_EXPORT_C(Fl_Color,Fl_Table_selection_color)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->selection_color();
  }
  FL_EXPORT_C(void,Fl_Table_set_selection_color)(fl_Table table,Fl_Color a){
    (static_cast<Fl_Table*>(table))->selection_color(a);
  }
  FL_EXPORT_C(const char*,Fl_Table_label)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->label();
  }
  FL_EXPORT_C(void,Fl_Table_copy_label)(fl_Table table,const char* new_label){
    (static_cast<Fl_Table*>(table))->copy_label(new_label);
  }
  FL_EXPORT_C(void,Fl_Table_set_label)(fl_Table table,const char* text){
    (static_cast<Fl_Table*>(table))->label(text);
  }
  FL_EXPORT_C(Fl_Labeltype,Fl_Table_labeltype)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->labeltype();
  }
  FL_EXPORT_C(void,Fl_Table_set_labeltype)(fl_Table table,Fl_Labeltype a){
    (static_cast<Fl_Table*>(table))->labeltype(a);
  }
  FL_EXPORT_C(void,Fl_Table_set_labelcolor)(fl_Table table,Fl_Color c){
    (static_cast<Fl_Table*>(table))->labelcolor(c);
  }
  FL_EXPORT_C(Fl_Font,Fl_Table_labelfont)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->labelfont();
  }
  FL_EXPORT_C(void,Fl_Table_set_labelfont)(fl_Table table,Fl_Font c){
    (static_cast<Fl_Table*>(table))->labelfont((static_cast<Fl_Font>(c)));
  }
  FL_EXPORT_C(Fl_Fontsize,Fl_Table_labelsize)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->labelsize();
  }
  FL_EXPORT_C(void,Fl_Table_set_labelsize)(fl_Table table,Fl_Fontsize pix){
    (static_cast<Fl_Table*>(table))->labelsize((static_cast<Fl_Fontsize>(pix)));
  }
  FL_EXPORT_C(fl_Image,Fl_Table_image)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->image();
  }
  FL_EXPORT_C(void,Fl_Table_set_image)(fl_Table table,fl_Image pix){
    (static_cast<Fl_Table*>(table))->image((static_cast<Fl_Image*>(pix)));
  }
  FL_EXPORT_C(fl_Image,Fl_Table_deimage)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->deimage();
  }
  FL_EXPORT_C(void,Fl_Table_set_deimage)(fl_Table table,fl_Image pix){
    (static_cast<Fl_Table*>(table))->deimage((static_cast<Fl_Image*>(pix)));
  }
  FL_EXPORT_C(const char*,Fl_Table_tooltip)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->tooltip();
  }
  FL_EXPORT_C(void,Fl_Table_copy_tooltip)(fl_Table table,const char* text){
    (static_cast<Fl_Table*>(table))->copy_tooltip(text);
  }
  FL_EXPORT_C(void,Fl_Table_set_tooltip)(fl_Table table,const char* text){
    (static_cast<Fl_Table*>(table))->tooltip(text);
  }
  FL_EXPORT_C(void,Fl_Table_set_callback_and_user_data)(fl_Table table,fl_Callback* cb,void* p){
    Fl_Table* castedWindow = (static_cast<Fl_Table*>(table));
    C_to_Fl_Callback* wrapper = new C_to_Fl_Callback(castedWindow, cb, p);
  }
  FL_EXPORT_C(void,Fl_Table_set_callback)(fl_Table table,fl_Callback* cb){
    Fl_Table* castedWindow = (static_cast<Fl_Table*>(table));
    C_to_Fl_Callback* wrapper = new C_to_Fl_Callback(castedWindow, cb);
  }
  FL_EXPORT_C(void*,Fl_Table_user_data)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->user_data();
  }
  FL_EXPORT_C(void,Fl_Table_set_user_data)(fl_Table table,void* v){
    (static_cast<Fl_Table*>(table))->user_data(v);
  }
  FL_EXPORT_C(long,Fl_Table_argument)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->argument();
  }
  FL_EXPORT_C(void,Fl_Table_set_argument)(fl_Table table,long v){
    (static_cast<Fl_Table*>(table))->argument(v);
  }
  FL_EXPORT_C(Fl_When,Fl_Table_when)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->when();
  }
  FL_EXPORT_C(void,Fl_Table_set_when)(fl_Table table,uchar i){
    (static_cast<Fl_Table*>(table))->when(i);
  }
  FL_EXPORT_C(unsigned int,Fl_Table_visible)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->visible();
  }
  FL_EXPORT_C(int,Fl_Table_visible_r)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->visible_r();
  }
  FL_EXPORT_C(void,Fl_Table_set_visible)(fl_Table table){
    (static_cast<Fl_Table*>(table))->visible();
  }
  FL_EXPORT_C(void,Fl_Table_clear_visible)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear_visible();
  }
  FL_EXPORT_C(unsigned int,Fl_Table_active)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->active();
  }
  FL_EXPORT_C(int,Fl_Table_active_r)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->active_r();
  }
  FL_EXPORT_C(void,Fl_Table_activate)(fl_Table table){
    (static_cast<Fl_Table*>(table))->activate();
  }
  FL_EXPORT_C(void,Fl_Table_deactivate)(fl_Table table){
    (static_cast<Fl_Table*>(table))->deactivate();
  }
  FL_EXPORT_C(unsigned int,Fl_Table_output)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->output();
  }
  FL_EXPORT_C(void,Fl_Table_set_output)(fl_Table table){
    (static_cast<Fl_Table*>(table))->output();
  }
  FL_EXPORT_C(void,Fl_Table_clear_output)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear_output();
  }
  FL_EXPORT_C(unsigned int,Fl_Table_takesevents)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->takesevents();
  }
  FL_EXPORT_C(void,Fl_Table_set_changed)(fl_Table table){
    (static_cast<Fl_Table*>(table))->changed();
  }
  FL_EXPORT_C(void,Fl_Table_clear_changed)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear_changed();
  }
  FL_EXPORT_C(int,Fl_Table_take_focus)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->take_focus();
  }
  FL_EXPORT_C(void,Fl_Table_set_visible_focus)(fl_Table table){
    (static_cast<Fl_Table*>(table))->visible_focus();
  }
  FL_EXPORT_C(void,Fl_Table_clear_visible_focus)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear_visible_focus();
  }
  FL_EXPORT_C(void,Fl_Table_modify_visible_focus)(fl_Table table,int v){
    (static_cast<Fl_Table*>(table))->visible_focus(v);
  }
  FL_EXPORT_C(unsigned int,Fl_Table_visible_focus)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->visible_focus();
  }
  FL_EXPORT_C(int,Fl_Table_contains)(fl_Table table,fl_Widget w){
    return (static_cast<Fl_Table*>(table))->contains((static_cast<Fl_Widget*>(w)));
  }
  FL_EXPORT_C(int,Fl_Table_inside)(fl_Table table,fl_Widget w){
    return (static_cast<Fl_Table*>(table))->inside((static_cast<Fl_Widget*>(w)));
  }
  FL_EXPORT_C(void,Fl_Table_redraw)(fl_Table table){
    (static_cast<Fl_Table*>(table))->redraw();
  }
  FL_EXPORT_C(void,Fl_Table_redraw_label)(fl_Table table){
    (static_cast<Fl_Table*>(table))->redraw_label();
  }
  FL_EXPORT_C(uchar,Fl_Table_damage)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->damage();
  }
  FL_EXPORT_C(void,Fl_Table_clear_damage_with_bitmask)(fl_Table table,uchar c){
    (static_cast<Fl_Table*>(table))->clear_damage(c);
  }
  FL_EXPORT_C(void,Fl_Table_clear_damage)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear_damage();
  }
  FL_EXPORT_C(void,Fl_Table_damage_with_text)(fl_Table table,uchar c){
    (static_cast<Fl_Table*>(table))->damage(c);
  }
  FL_EXPORT_C(void,Fl_Table_damage_inside_widget)(fl_Table table,uchar c,int x,int y,int w,int h){
    (static_cast<Fl_Table*>(table))->damage(c,x,y,w,h);
  }
  FL_EXPORT_C(void,Fl_Table_draw_label)(fl_Table table,int x,int y,int w,int h,Fl_Align alignment){
    (static_cast<Fl_Table*>(table))->draw_label(x,y,w,h,alignment);
  }
  FL_EXPORT_C(void,Fl_Table_measure_label)(fl_Table table,int& ww,int& hh){
    (static_cast<Fl_Table*>(table))->measure_label(ww,hh);
  }
  FL_EXPORT_C(fl_Group,Fl_Table_as_group)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->as_group();
  }
  FL_EXPORT_C(fl_Gl_Window,Fl_Table_as_gl_window)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->as_gl_window();
  }
  FL_EXPORT_C(void,Fl_Table_clear)(fl_Table table){
    (static_cast<Fl_Table*>(table))->clear();
  }
  FL_EXPORT_C(void,Fl_Table_set_resizable_by_reference)(fl_Table table,fl_Widget o){
    (static_cast<Fl_Table*>(table))->resizable((static_cast<Fl_Widget*>(o)));
  }
  FL_EXPORT_C(void,Fl_Table_set_resizable)(fl_Table table,fl_Widget o){
    (static_cast<Fl_Table*>(table))->resizable((static_cast<Fl_Widget*>(o)));
  }
  FL_EXPORT_C(fl_Widget,Fl_Table_resizable)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->resizable();
  }
  FL_EXPORT_C(void,Fl_Table_add_resizable)(fl_Table table,fl_Widget o){
    return (static_cast<Fl_Table*>(table))->add_resizable(*(static_cast<Fl_Widget*>(o)));
  }
  FL_EXPORT_C(void,Fl_Table_set_clip_children)(fl_Table table,int c){
    return (static_cast<Fl_Table*>(table))->clip_children(c);
  }
  FL_EXPORT_C(unsigned int,Fl_Table_clip_children)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->clip_children();
  }
  FL_EXPORT_C(void,Fl_Table_focus)(fl_Table table, fl_Widget W){
    return (static_cast<Fl_Table*>(table))->focus((static_cast<Fl_Widget*>(W)));
  }
  FL_EXPORT_C(fl_Widget,Fl_Table__ddfdesign_kludge)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->_ddfdesign_kludge();
  }

  FL_EXPORT_C(void,Fl_Table_set_table_box)(fl_Table table,Fl_Boxtype val){
    return (static_cast<Fl_Table*>(table))->table_box(val);
  }
  FL_EXPORT_C(Fl_Boxtype,Fl_Table_table_box)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->table_box();
  }
  FL_EXPORT_C(int,Fl_Table_cols)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->cols();
  }
  FL_EXPORT_C(void, Fl_Table_set_visible_cells)(fl_Table table,int& r1, int& r2, int& c1, int& c2){
    return (static_cast<Fl_Table*>(table))->visible_cells(r1,r2,c1,c2);
  };
  FL_EXPORT_C(int,Fl_Table_is_interactive_resize)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->is_interactive_resize();
  }
  FL_EXPORT_C(int,Fl_Table_row_resize)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_resize();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_resize)(fl_Table table,int flag){
    return (static_cast<Fl_Table*>(table))->row_resize(flag);
  }
  FL_EXPORT_C(int,Fl_Table_col_resize)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_resize();
  }
  FL_EXPORT_C(void,Fl_Table_set_col_resize)(fl_Table table,int flag){
    return (static_cast<Fl_Table*>(table))->col_resize(flag);
  }
  FL_EXPORT_C(int,Fl_Table_col_resize_min)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_resize_min();
  }
  FL_EXPORT_C(void,Fl_Table_set_col_resize_min)(fl_Table table,int val){
    return (static_cast<Fl_Table*>(table))->col_resize_min(val);
  }
  FL_EXPORT_C(int,Fl_Table_row_resize_min)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_resize_min();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_resize_min)(fl_Table table,int val){
    return (static_cast<Fl_Table*>(table))->row_resize_min(val);
  }
  FL_EXPORT_C(int,Fl_Table_row_header)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_header();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_header)(fl_Table table,int flag){
    return (static_cast<Fl_Table*>(table))->row_header(flag);
  }
  FL_EXPORT_C(int,Fl_Table_col_header)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_header();
  }
  FL_EXPORT_C(void,Fl_Table_set_col_header)(fl_Table table,int flag){
    return (static_cast<Fl_Table*>(table))->col_header(flag);
  }
  FL_EXPORT_C(void,Fl_Table_set_col_header_height)(fl_Table table,int height){
    return (static_cast<Fl_Table*>(table))->col_header_height(height);
  }
  FL_EXPORT_C(int,Fl_Table_col_header_height)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_header_height();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_header_width)(fl_Table table,int width){
    return (static_cast<Fl_Table*>(table))->row_header_width(width);
  }
  FL_EXPORT_C(int,Fl_Table_row_header_width)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_header_width();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_header_color)(fl_Table table,Fl_Color val){
    return (static_cast<Fl_Table*>(table))->row_header_color(val);
  }
  FL_EXPORT_C(Fl_Color,Fl_Table_row_header_color)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_header_color();
  }
  FL_EXPORT_C(void,Fl_Table_set_col_header_color)(fl_Table table,Fl_Color val){
    return (static_cast<Fl_Table*>(table))->col_header_color(val);
  }
  FL_EXPORT_C(Fl_Color,Fl_Table_col_header_color)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_header_color();
  }
  FL_EXPORT_C(void,Fl_Table_set_row_height)(fl_Table table,int row,int height){
    return (static_cast<Fl_Table*>(table))->row_height(row,height);
  }
  FL_EXPORT_C(int,Fl_Table_row_height)(fl_Table table,int row){
    return (static_cast<Fl_Table*>(table))->row_height(row);
  }
  FL_EXPORT_C(void,Fl_Table_set_col_width)(fl_Table table,int col,int width){
    return (static_cast<Fl_Table*>(table))->col_width(col,width);
  }
  FL_EXPORT_C(int,Fl_Table_col_width)(fl_Table table,int col){
    return (static_cast<Fl_Table*>(table))->col_width(col);
  }
  FL_EXPORT_C(void,Fl_Table_set_row_height_all)(fl_Table table,int height){
    return (static_cast<Fl_Table*>(table))->row_height_all(height);
  }
  FL_EXPORT_C(void,Fl_Table_set_col_width_all)(fl_Table table,int width){
    return (static_cast<Fl_Table*>(table))->col_width_all(width);
  }
  FL_EXPORT_C(void,Fl_Table_set_row_position)(fl_Table table,int row){
    return (static_cast<Fl_Table*>(table))->row_position(row);
  }
  FL_EXPORT_C(void,Fl_Table_set_col_position)(fl_Table table,int col){
    return (static_cast<Fl_Table*>(table))->col_position(col);
  }
  FL_EXPORT_C(int,Fl_Table_row_position)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->row_position();
  }
  FL_EXPORT_C(int,Fl_Table_col_position)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->col_position();
  }
  FL_EXPORT_C(void,Fl_Table_set_top_row)(fl_Table table,int row){
    return (static_cast<Fl_Table*>(table))->top_row(row);
  }
  FL_EXPORT_C(int,Fl_Table_top_row)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->top_row();
  }
  FL_EXPORT_C(int,Fl_Table_is_selected)(fl_Table table,int r,int c){
    return (static_cast<Fl_Table*>(table))->is_selected(r,c);
  }
  FL_EXPORT_C(void,Fl_Table_get_selection)(fl_Table table,int &row_top,int &col_left,int &row_bot,int &col_right){
    return (static_cast<Fl_Table*>(table))->get_selection(row_top,col_left,row_bot,col_right);
  }
  FL_EXPORT_C(void,Fl_Table_set_selection)(fl_Table table,int row_top,int col_left,int row_bot,int col_right){
    return (static_cast<Fl_Table*>(table))->set_selection(row_top,col_left,row_bot,col_right);
  }
  FL_EXPORT_C(int,Fl_Table_move_cursor)(fl_Table table,int R,int C){
    return (static_cast<Fl_Table*>(table))->move_cursor(R,C);
  }
  FL_EXPORT_C(void,Fl_Table_resize)(fl_Table table,int X,int Y,int W,int H){
    return (static_cast<Fl_Table*>(table))->resize(X,Y,W,H);
  }
  FL_EXPORT_C(void,Fl_Table_draw)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->draw();
  }
  FL_EXPORT_C(void,Fl_Table_init_sizes)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->init_sizes();
  }
  FL_EXPORT_C(void,Fl_Table_add)(fl_Table table,fl_Widget wgt){
    return (static_cast<Fl_Table*>(table))->add((static_cast<Fl_Widget*>(wgt)));
  }
  FL_EXPORT_C(void,Fl_Table_insert)(fl_Table table,fl_Widget wgt,int n){
    (static_cast<Fl_Table*>(table))->insert(*(static_cast<Fl_Widget*>(wgt)),n);
  }
  FL_EXPORT_C(void, Fl_Table_insert_with_widget)(fl_Table table,fl_Widget wgt, fl_Widget w2){
    (static_cast<Fl_Table*>(table))->insert(*(static_cast<Fl_Widget*>(wgt)),(static_cast<Fl_Widget*>(w2)));
  };
  FL_EXPORT_C(void,Fl_Table_remove)(fl_Table table,fl_Widget wgt){
    return (static_cast<Fl_Table*>(table))->remove(*(static_cast<Fl_Widget*>(wgt)));
  }
  FL_EXPORT_C(void,Fl_Table_begin)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->begin();
  }
  FL_EXPORT_C(void,Fl_Table_end)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->end();
  }
  FL_EXPORT_C(fl_Widget*,Fl_Table_array)(fl_Table table){
    return (fl_Widget*)(static_cast<Fl_Table*>(table))->array();
  }
  FL_EXPORT_C(fl_Widget,Fl_Table_child)(fl_Table table,int n){
    return (static_cast<Fl_Table*>(table))->child(n);
  }
  FL_EXPORT_C(int,Fl_Table_children)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->children();
  }
  FL_EXPORT_C(int,Fl_Table_find)(fl_Table table,fl_Widget wgt){
    return (static_cast<Fl_Table*>(table))->find((static_cast<Fl_Widget*>(wgt)));
  }
  FL_EXPORT_C(int,Fl_Table_callback_row)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->callback_row();
  }
  FL_EXPORT_C(int,Fl_Table_callback_col)(fl_Table table){
    return (static_cast<Fl_Table*>(table))->callback_col();
  }
  FL_EXPORT_C(TableContextC,Fl_Table_callback_context)(fl_Table table){
    Fl_Table* t = (static_cast<Fl_Table*>(table));
    Fl_Table::TableContext context = t->callback_context();
    TableContextC ret = (TableContextC)-1;
    switch(context){
    case Fl_Table::CONTEXT_NONE:      {ret = CONTEXT_NONEC;      break;}
    case Fl_Table::CONTEXT_STARTPAGE: {ret = CONTEXT_STARTPAGEC; break;}
    case Fl_Table::CONTEXT_ENDPAGE:   {ret = CONTEXT_ENDPAGEC;   break;}
    case Fl_Table::CONTEXT_ROW_HEADER:{ret = CONTEXT_ROW_HEADERC;break;}
    case Fl_Table::CONTEXT_COL_HEADER:{ret = CONTEXT_COL_HEADERC;break;}
    case Fl_Table::CONTEXT_CELL:      {ret = CONTEXT_CELLC;      break;}
    case Fl_Table::CONTEXT_TABLE:     {ret = CONTEXT_TABLEC;     break;}
    case Fl_Table::CONTEXT_RC_RESIZE: {ret = CONTEXT_RC_RESIZEC; break;}
    default:                          {ret = TableContextC(-1);  break;}
    }
    return ret;
  }
  FL_EXPORT_C(void,Fl_Table_do_callback)(fl_Table table, TableContextC tableContext, int row, int col){
    Fl_Table::TableContext c = (Fl_Table::TableContext)-1;
    switch(tableContext){
    case CONTEXT_NONEC:      {c = Fl_Table::CONTEXT_NONE;      break;}
    case CONTEXT_STARTPAGEC: {c = Fl_Table::CONTEXT_STARTPAGE; break;}
    case CONTEXT_ENDPAGEC:   {c = Fl_Table::CONTEXT_ENDPAGE;   break;}
    case CONTEXT_ROW_HEADERC:{c = Fl_Table::CONTEXT_ROW_HEADER;break;}
    case CONTEXT_COL_HEADERC:{c = Fl_Table::CONTEXT_COL_HEADER;break;}
    case CONTEXT_CELLC:      {c = Fl_Table::CONTEXT_CELL;      break;}
    case CONTEXT_TABLEC:     {c = Fl_Table::CONTEXT_TABLE;     break;}
    case CONTEXT_RC_RESIZEC: {c = Fl_Table::CONTEXT_RC_RESIZE; break;}
    default:                 {c = (Fl_Table::TableContext)-1;  break;}
    }
    (static_cast<Fl_Table*>(table))->do_callback(c, row, col);
  }
#ifdef __cplusplus
}
#endif