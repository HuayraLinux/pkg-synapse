/* wrap-label.c generated by valac 0.10.4, the Vala compiler
 * generated from wrap-label.vala, do not modify */

/*
 * Copyright (C) 2010 Michal Hruby <michal.mhr@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA.
 *
 * Authored by Michal Hruby <michal.mhr@gmail.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <float.h>
#include <math.h>
#include <gdk/gdk.h>
#include <pango/pango.h>


#define UI_WIDGETS_TYPE_WRAP_LABEL (ui_widgets_wrap_label_get_type ())
#define UI_WIDGETS_WRAP_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UI_WIDGETS_TYPE_WRAP_LABEL, UIWidgetsWrapLabel))
#define UI_WIDGETS_WRAP_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UI_WIDGETS_TYPE_WRAP_LABEL, UIWidgetsWrapLabelClass))
#define UI_WIDGETS_IS_WRAP_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UI_WIDGETS_TYPE_WRAP_LABEL))
#define UI_WIDGETS_IS_WRAP_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UI_WIDGETS_TYPE_WRAP_LABEL))
#define UI_WIDGETS_WRAP_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UI_WIDGETS_TYPE_WRAP_LABEL, UIWidgetsWrapLabelClass))

typedef struct _UIWidgetsWrapLabel UIWidgetsWrapLabel;
typedef struct _UIWidgetsWrapLabelClass UIWidgetsWrapLabelClass;
typedef struct _UIWidgetsWrapLabelPrivate UIWidgetsWrapLabelPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UIWidgetsWrapLabel {
	GtkLabel parent_instance;
	UIWidgetsWrapLabelPrivate * priv;
};

struct _UIWidgetsWrapLabelClass {
	GtkLabelClass parent_class;
};

struct _UIWidgetsWrapLabelPrivate {
	float orig_yalign;
	gboolean _wrap;
};


static gpointer ui_widgets_wrap_label_parent_class = NULL;

GType ui_widgets_wrap_label_get_type (void) G_GNUC_CONST;
#define UI_WIDGETS_WRAP_LABEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UI_WIDGETS_TYPE_WRAP_LABEL, UIWidgetsWrapLabelPrivate))
enum  {
	UI_WIDGETS_WRAP_LABEL_DUMMY_PROPERTY,
	UI_WIDGETS_WRAP_LABEL_WRAP
};
UIWidgetsWrapLabel* ui_widgets_wrap_label_new (void);
UIWidgetsWrapLabel* ui_widgets_wrap_label_construct (GType object_type);
static void ui_widgets_wrap_label_real_size_allocate (GtkWidget* base, GdkRectangle* allocation);
static void ui_widgets_wrap_label_real_size_request (GtkWidget* base, GtkRequisition* req);
gboolean ui_widgets_wrap_label_get_wrap (UIWidgetsWrapLabel* self);
void ui_widgets_wrap_label_set_wrap (UIWidgetsWrapLabel* self, gboolean value);
static GObject * ui_widgets_wrap_label_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void ui_widgets_wrap_label_finalize (GObject* obj);
static void ui_widgets_wrap_label_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void ui_widgets_wrap_label_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UIWidgetsWrapLabel* ui_widgets_wrap_label_construct (GType object_type) {
	UIWidgetsWrapLabel * self = NULL;
	self = (UIWidgetsWrapLabel*) g_object_new (object_type, "xalign", 0.0f, "wrap", FALSE, NULL);
	return self;
}


UIWidgetsWrapLabel* ui_widgets_wrap_label_new (void) {
	return ui_widgets_wrap_label_construct (UI_WIDGETS_TYPE_WRAP_LABEL);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void ui_widgets_wrap_label_real_size_allocate (GtkWidget* base, GdkRectangle* allocation) {
	UIWidgetsWrapLabel * self;
	PangoLayout* layout;
	gint lw = 0;
	gint lh = 0;
	self = (UIWidgetsWrapLabel*) base;
	layout = _g_object_ref0 (gtk_label_get_layout ((GtkLabel*) self));
	pango_layout_set_width (layout, (*allocation).width * PANGO_SCALE);
	pango_layout_get_pixel_size (layout, &lw, &lh);
	g_object_set ((GtkWidget*) self, "height-request", lh, NULL);
	GTK_WIDGET_CLASS (ui_widgets_wrap_label_parent_class)->size_allocate ((GtkWidget*) GTK_LABEL (self), allocation);
	_g_object_unref0 (layout);
}


static void ui_widgets_wrap_label_real_size_request (GtkWidget* base, GtkRequisition* req) {
	UIWidgetsWrapLabel * self;
	self = (UIWidgetsWrapLabel*) base;
	GTK_WIDGET_CLASS (ui_widgets_wrap_label_parent_class)->size_request ((GtkWidget*) GTK_LABEL (self), req);
	if (self->priv->_wrap) {
		(*req).width = 1;
	}
}


gboolean ui_widgets_wrap_label_get_wrap (UIWidgetsWrapLabel* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_wrap;
	return result;
}


void ui_widgets_wrap_label_set_wrap (UIWidgetsWrapLabel* self, gboolean value) {
	gint _tmp0_ = 0;
	PangoEllipsizeMode _tmp1_ = 0;
	float _tmp3_ = 0.0F;
	g_return_if_fail (self != NULL);
	self->priv->_wrap = value;
	if (self->priv->_wrap) {
		_tmp0_ = -1;
	} else {
		_tmp0_ = 10;
	}
	gtk_label_set_max_width_chars ((GtkLabel*) self, _tmp0_);
	if (self->priv->_wrap) {
		_tmp1_ = PANGO_ELLIPSIZE_NONE;
	} else {
		_tmp1_ = PANGO_ELLIPSIZE_END;
	}
	gtk_label_set_ellipsize ((GtkLabel*) self, _tmp1_);
	if (!self->priv->_wrap) {
		float _tmp2_;
		self->priv->orig_yalign = (g_object_get ((GtkMisc*) self, "yalign", &_tmp2_, NULL), _tmp2_);
	}
	if (self->priv->_wrap) {
		_tmp3_ = 0.0f;
	} else {
		_tmp3_ = self->priv->orig_yalign;
	}
	g_object_set ((GtkMisc*) self, "yalign", _tmp3_, NULL);
	gtk_widget_queue_resize ((GtkWidget*) self);
	g_object_notify ((GObject *) self, "wrap");
}


static GObject * ui_widgets_wrap_label_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UIWidgetsWrapLabel * self;
	parent_class = G_OBJECT_CLASS (ui_widgets_wrap_label_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UI_WIDGETS_WRAP_LABEL (obj);
	{
	}
	return obj;
}


static void ui_widgets_wrap_label_class_init (UIWidgetsWrapLabelClass * klass) {
	ui_widgets_wrap_label_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UIWidgetsWrapLabelPrivate));
	GTK_WIDGET_CLASS (klass)->size_allocate = ui_widgets_wrap_label_real_size_allocate;
	GTK_WIDGET_CLASS (klass)->size_request = ui_widgets_wrap_label_real_size_request;
	G_OBJECT_CLASS (klass)->get_property = ui_widgets_wrap_label_get_property;
	G_OBJECT_CLASS (klass)->set_property = ui_widgets_wrap_label_set_property;
	G_OBJECT_CLASS (klass)->constructor = ui_widgets_wrap_label_constructor;
	G_OBJECT_CLASS (klass)->finalize = ui_widgets_wrap_label_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UI_WIDGETS_WRAP_LABEL_WRAP, g_param_spec_boolean ("wrap", "wrap", "wrap", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void ui_widgets_wrap_label_instance_init (UIWidgetsWrapLabel * self) {
	self->priv = UI_WIDGETS_WRAP_LABEL_GET_PRIVATE (self);
	self->priv->orig_yalign = 0.5f;
	self->priv->_wrap = FALSE;
}


static void ui_widgets_wrap_label_finalize (GObject* obj) {
	UIWidgetsWrapLabel * self;
	self = UI_WIDGETS_WRAP_LABEL (obj);
	G_OBJECT_CLASS (ui_widgets_wrap_label_parent_class)->finalize (obj);
}


GType ui_widgets_wrap_label_get_type (void) {
	static volatile gsize ui_widgets_wrap_label_type_id__volatile = 0;
	if (g_once_init_enter (&ui_widgets_wrap_label_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UIWidgetsWrapLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) ui_widgets_wrap_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UIWidgetsWrapLabel), 0, (GInstanceInitFunc) ui_widgets_wrap_label_instance_init, NULL };
		GType ui_widgets_wrap_label_type_id;
		ui_widgets_wrap_label_type_id = g_type_register_static (GTK_TYPE_LABEL, "UIWidgetsWrapLabel", &g_define_type_info, 0);
		g_once_init_leave (&ui_widgets_wrap_label_type_id__volatile, ui_widgets_wrap_label_type_id);
	}
	return ui_widgets_wrap_label_type_id__volatile;
}


static void ui_widgets_wrap_label_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UIWidgetsWrapLabel * self;
	self = UI_WIDGETS_WRAP_LABEL (object);
	switch (property_id) {
		case UI_WIDGETS_WRAP_LABEL_WRAP:
		g_value_set_boolean (value, ui_widgets_wrap_label_get_wrap (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void ui_widgets_wrap_label_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UIWidgetsWrapLabel * self;
	self = UI_WIDGETS_WRAP_LABEL (object);
	switch (property_id) {
		case UI_WIDGETS_WRAP_LABEL_WRAP:
		ui_widgets_wrap_label_set_wrap (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




