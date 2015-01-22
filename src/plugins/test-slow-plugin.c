/* test-slow-plugin.c generated by valac 0.10.4, the Vala compiler
 * generated from test-slow-plugin.vala, do not modify */

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
#include <synapse-core.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define SYNAPSE_TYPE_TEST_SLOW_PLUGIN (synapse_test_slow_plugin_get_type ())
#define SYNAPSE_TEST_SLOW_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_TEST_SLOW_PLUGIN, SynapseTestSlowPlugin))
#define SYNAPSE_TEST_SLOW_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYNAPSE_TYPE_TEST_SLOW_PLUGIN, SynapseTestSlowPluginClass))
#define SYNAPSE_IS_TEST_SLOW_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_TEST_SLOW_PLUGIN))
#define SYNAPSE_IS_TEST_SLOW_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYNAPSE_TYPE_TEST_SLOW_PLUGIN))
#define SYNAPSE_TEST_SLOW_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYNAPSE_TYPE_TEST_SLOW_PLUGIN, SynapseTestSlowPluginClass))

typedef struct _SynapseTestSlowPlugin SynapseTestSlowPlugin;
typedef struct _SynapseTestSlowPluginClass SynapseTestSlowPluginClass;
typedef struct _SynapseTestSlowPluginPrivate SynapseTestSlowPluginPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT (synapse_test_slow_plugin_test_result_get_type ())
#define SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT, SynapseTestSlowPluginTestResult))
#define SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT, SynapseTestSlowPluginTestResultClass))
#define SYNAPSE_TEST_SLOW_PLUGIN_IS_TEST_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT))
#define SYNAPSE_TEST_SLOW_PLUGIN_IS_TEST_RESULT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT))
#define SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT, SynapseTestSlowPluginTestResultClass))

typedef struct _SynapseTestSlowPluginTestResult SynapseTestSlowPluginTestResult;
typedef struct _SynapseTestSlowPluginTestResultClass SynapseTestSlowPluginTestResultClass;
typedef struct _SynapseTestSlowPluginSearchData SynapseTestSlowPluginSearchData;
typedef struct _SynapseTestSlowPluginTestResultPrivate SynapseTestSlowPluginTestResultPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _SynapseTestSlowPlugin {
	GObject parent_instance;
	SynapseTestSlowPluginPrivate * priv;
};

struct _SynapseTestSlowPluginClass {
	GObjectClass parent_class;
};

struct _SynapseTestSlowPluginPrivate {
	gboolean _enabled;
};

struct _SynapseTestSlowPluginSearchData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	SynapseTestSlowPlugin* self;
	SynapseQuery q;
	SynapseResultSet* result;
	SynapseResultSet* rs;
	SynapseTestSlowPluginTestResult* _tmp0_;
	GError * _inner_error_;
};

struct _SynapseTestSlowPluginTestResult {
	GObject parent_instance;
	SynapseTestSlowPluginTestResultPrivate * priv;
};

struct _SynapseTestSlowPluginTestResultClass {
	GObjectClass parent_class;
};

struct _SynapseTestSlowPluginTestResultPrivate {
	char* _title;
	char* _description;
	char* _icon_name;
	gboolean _has_thumbnail;
	char* _thumbnail_path;
	char* _uri;
	SynapseMatchType _match_type;
};


static gpointer synapse_test_slow_plugin_test_result_parent_class = NULL;
static SynapseMatchIface* synapse_test_slow_plugin_test_result_synapse_match_parent_iface = NULL;
static gpointer synapse_test_slow_plugin_parent_class = NULL;
static SynapseActivatableIface* synapse_test_slow_plugin_synapse_activatable_parent_iface = NULL;
static SynapseItemProviderIface* synapse_test_slow_plugin_synapse_item_provider_parent_iface = NULL;

GType synapse_test_slow_plugin_get_type (void) G_GNUC_CONST;
#define SYNAPSE_TEST_SLOW_PLUGIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SYNAPSE_TYPE_TEST_SLOW_PLUGIN, SynapseTestSlowPluginPrivate))
enum  {
	SYNAPSE_TEST_SLOW_PLUGIN_DUMMY_PROPERTY,
	SYNAPSE_TEST_SLOW_PLUGIN_ENABLED
};
static void synapse_test_slow_plugin_real_activate (SynapseActivatable* base);
static void synapse_test_slow_plugin_real_deactivate (SynapseActivatable* base);
static void synapse_test_slow_plugin_real_search_data_free (gpointer _data);
static void synapse_test_slow_plugin_real_search (SynapseItemProvider* base, SynapseQuery* q, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void synapse_test_slow_plugin_search_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean synapse_test_slow_plugin_real_search_co (SynapseTestSlowPluginSearchData* data);
static gboolean _synapse_test_slow_plugin_real_search_co_gsource_func (gpointer self);
static SynapseTestSlowPluginTestResult* synapse_test_slow_plugin_test_result_new (const char* query);
static SynapseTestSlowPluginTestResult* synapse_test_slow_plugin_test_result_construct (GType object_type, const char* query);
static GType synapse_test_slow_plugin_test_result_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
SynapseTestSlowPlugin* synapse_test_slow_plugin_new (void);
SynapseTestSlowPlugin* synapse_test_slow_plugin_construct (GType object_type);
#define SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT, SynapseTestSlowPluginTestResultPrivate))
enum  {
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_DUMMY_PROPERTY,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_TITLE,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_DESCRIPTION,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_ICON_NAME,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_HAS_THUMBNAIL,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_THUMBNAIL_PATH,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_URI,
	SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_MATCH_TYPE
};
static const char* synapse_test_slow_plugin_test_result_get_uri (SynapseTestSlowPluginTestResult* self);
static void synapse_test_slow_plugin_test_result_set_uri (SynapseTestSlowPluginTestResult* self, const char* value);
static void synapse_test_slow_plugin_test_result_finalize (GObject* obj);
static void synapse_test_slow_plugin_test_result_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void synapse_test_slow_plugin_test_result_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void synapse_test_slow_plugin_finalize (GObject* obj);
static void synapse_test_slow_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void synapse_test_slow_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



static void synapse_test_slow_plugin_real_activate (SynapseActivatable* base) {
	SynapseTestSlowPlugin * self;
	self = (SynapseTestSlowPlugin*) base;
}


static void synapse_test_slow_plugin_real_deactivate (SynapseActivatable* base) {
	SynapseTestSlowPlugin * self;
	self = (SynapseTestSlowPlugin*) base;
}


static void synapse_test_slow_plugin_real_search_data_free (gpointer _data) {
	SynapseTestSlowPluginSearchData* data;
	data = _data;
	synapse_query_destroy (&data->q);
	_g_object_unref0 (data->result);
	g_object_unref (data->self);
	g_slice_free (SynapseTestSlowPluginSearchData, data);
}


static void synapse_test_slow_plugin_real_search (SynapseItemProvider* base, SynapseQuery* q, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	SynapseTestSlowPlugin * self;
	SynapseTestSlowPluginSearchData* _data_;
	SynapseQuery _tmp0_ = {0};
	self = (SynapseTestSlowPlugin*) base;
	_data_ = g_slice_new0 (SynapseTestSlowPluginSearchData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, synapse_test_slow_plugin_real_search);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, synapse_test_slow_plugin_real_search_data_free);
	_data_->self = g_object_ref (self);
	_data_->q = (synapse_query_copy (q, &_tmp0_), _tmp0_);
	synapse_test_slow_plugin_real_search_co (_data_);
}


static SynapseResultSet* synapse_test_slow_plugin_real_search_finish (SynapseItemProvider* base, GAsyncResult* _res_, GError** error) {
	SynapseResultSet* result;
	SynapseTestSlowPluginSearchData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void synapse_test_slow_plugin_search_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	SynapseTestSlowPluginSearchData* data;
	data = _user_data_;
	data->_res_ = _res_;
	synapse_test_slow_plugin_real_search_co (data);
}


static gboolean _synapse_test_slow_plugin_real_search_co_gsource_func (gpointer self) {
	gboolean result;
	result = synapse_test_slow_plugin_real_search_co (self);
	return result;
}


static gboolean synapse_test_slow_plugin_real_search_co (SynapseTestSlowPluginSearchData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 41:
		goto _state_41;
		case 42:
		goto _state_42;
	}
	_state_0:
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _synapse_test_slow_plugin_real_search_co_gsource_func, data, NULL);
	data->_state_ = 41;
	return FALSE;
	_state_41:
	;
	synapse_query_check_cancellable (&data->q, &data->_inner_error_);
	if (data->_inner_error_ != NULL) {
		if (data->_inner_error_->domain == SYNAPSE_SEARCH_ERROR) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			{
				if (data->_state_ == 0) {
					g_simple_async_result_complete_in_idle (data->_async_result);
				} else {
					g_simple_async_result_complete (data->_async_result);
				}
				g_object_unref (data->_async_result);
				return FALSE;
			}
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
	}
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 2000, _synapse_test_slow_plugin_real_search_co_gsource_func, data, NULL);
	data->_state_ = 42;
	return FALSE;
	_state_42:
	;
	synapse_query_check_cancellable (&data->q, &data->_inner_error_);
	if (data->_inner_error_ != NULL) {
		if (data->_inner_error_->domain == SYNAPSE_SEARCH_ERROR) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			{
				if (data->_state_ == 0) {
					g_simple_async_result_complete_in_idle (data->_async_result);
				} else {
					g_simple_async_result_complete (data->_async_result);
				}
				g_object_unref (data->_async_result);
				return FALSE;
			}
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
	}
	synapse_utils_logger_debug ((GObject*) data->self, "test-slow-plugin.vala:69: finished search for \"%s\"", data->q.query_string, NULL);
	data->rs = synapse_result_set_new ();
	synapse_result_set_add (data->rs, (SynapseMatch*) (data->_tmp0_ = synapse_test_slow_plugin_test_result_new (data->q.query_string)), 0);
	_g_object_unref0 (data->_tmp0_);
	data->result = data->rs;
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
	_g_object_unref0 (data->rs);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


SynapseTestSlowPlugin* synapse_test_slow_plugin_construct (GType object_type) {
	SynapseTestSlowPlugin * self = NULL;
	self = (SynapseTestSlowPlugin*) g_object_new (object_type, NULL);
	return self;
}


SynapseTestSlowPlugin* synapse_test_slow_plugin_new (void) {
	return synapse_test_slow_plugin_construct (SYNAPSE_TYPE_TEST_SLOW_PLUGIN);
}


static gboolean synapse_test_slow_plugin_real_get_enabled (SynapseActivatable* base) {
	gboolean result;
	SynapseTestSlowPlugin* self;
	self = (SynapseTestSlowPlugin*) base;
	result = self->priv->_enabled;
	return result;
}


static void synapse_test_slow_plugin_real_set_enabled (SynapseActivatable* base, gboolean value) {
	SynapseTestSlowPlugin* self;
	self = (SynapseTestSlowPlugin*) base;
	self->priv->_enabled = value;
	g_object_notify ((GObject *) self, "enabled");
}


static char* string_strip (const char* self) {
	char* result = NULL;
	char* _result_;
	g_return_val_if_fail (self != NULL, NULL);
	_result_ = g_strdup (self);
	g_strstrip (_result_);
	result = _result_;
	return result;
}


static SynapseTestSlowPluginTestResult* synapse_test_slow_plugin_test_result_construct (GType object_type, const char* query) {
	SynapseTestSlowPluginTestResult * self = NULL;
	char* _tmp0_;
	char* _tmp1_;
	g_return_val_if_fail (query != NULL, NULL);
	self = (SynapseTestSlowPluginTestResult*) g_object_new (object_type, "title", _tmp1_ = g_strconcat ("Test result for ", _tmp0_ = string_strip (query), NULL), "description", "by TestSlowPlugin", "icon-name", "unknown", "has-thumbnail", FALSE, "match-type", SYNAPSE_MATCH_TYPE_UNKNOWN, NULL);
	_g_free0 (_tmp1_);
	_g_free0 (_tmp0_);
	return self;
}


static SynapseTestSlowPluginTestResult* synapse_test_slow_plugin_test_result_new (const char* query) {
	return synapse_test_slow_plugin_test_result_construct (SYNAPSE_TEST_SLOW_PLUGIN_TYPE_TEST_RESULT, query);
}


static const char* synapse_test_slow_plugin_test_result_real_get_title (SynapseMatch* base) {
	const char* result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_title;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_title (SynapseMatch* base, const char* value) {
	SynapseTestSlowPluginTestResult* self;
	char* _tmp0_;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_title = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_title), _tmp0_);
	g_object_notify ((GObject *) self, "title");
}


static const char* synapse_test_slow_plugin_test_result_real_get_description (SynapseMatch* base) {
	const char* result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_description;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_description (SynapseMatch* base, const char* value) {
	SynapseTestSlowPluginTestResult* self;
	char* _tmp0_;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_description = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_description), _tmp0_);
	g_object_notify ((GObject *) self, "description");
}


static const char* synapse_test_slow_plugin_test_result_real_get_icon_name (SynapseMatch* base) {
	const char* result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_icon_name;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_icon_name (SynapseMatch* base, const char* value) {
	SynapseTestSlowPluginTestResult* self;
	char* _tmp0_;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_icon_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon_name), _tmp0_);
	g_object_notify ((GObject *) self, "icon-name");
}


static gboolean synapse_test_slow_plugin_test_result_real_get_has_thumbnail (SynapseMatch* base) {
	gboolean result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_has_thumbnail;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_has_thumbnail (SynapseMatch* base, gboolean value) {
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_has_thumbnail = value;
	g_object_notify ((GObject *) self, "has-thumbnail");
}


static const char* synapse_test_slow_plugin_test_result_real_get_thumbnail_path (SynapseMatch* base) {
	const char* result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_thumbnail_path;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_thumbnail_path (SynapseMatch* base, const char* value) {
	SynapseTestSlowPluginTestResult* self;
	char* _tmp0_;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_thumbnail_path = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_thumbnail_path), _tmp0_);
	g_object_notify ((GObject *) self, "thumbnail-path");
}


static const char* synapse_test_slow_plugin_test_result_get_uri (SynapseTestSlowPluginTestResult* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_uri;
	return result;
}


static void synapse_test_slow_plugin_test_result_set_uri (SynapseTestSlowPluginTestResult* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_uri = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_uri), _tmp0_);
	g_object_notify ((GObject *) self, "uri");
}


static SynapseMatchType synapse_test_slow_plugin_test_result_real_get_match_type (SynapseMatch* base) {
	SynapseMatchType result;
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	result = self->priv->_match_type;
	return result;
}


static void synapse_test_slow_plugin_test_result_real_set_match_type (SynapseMatch* base, SynapseMatchType value) {
	SynapseTestSlowPluginTestResult* self;
	self = (SynapseTestSlowPluginTestResult*) base;
	self->priv->_match_type = value;
	g_object_notify ((GObject *) self, "match-type");
}


static void synapse_test_slow_plugin_test_result_class_init (SynapseTestSlowPluginTestResultClass * klass) {
	synapse_test_slow_plugin_test_result_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SynapseTestSlowPluginTestResultPrivate));
	G_OBJECT_CLASS (klass)->get_property = synapse_test_slow_plugin_test_result_get_property;
	G_OBJECT_CLASS (klass)->set_property = synapse_test_slow_plugin_test_result_set_property;
	G_OBJECT_CLASS (klass)->finalize = synapse_test_slow_plugin_test_result_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_TITLE, "title");
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_DESCRIPTION, "description");
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_ICON_NAME, "icon-name");
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_HAS_THUMBNAIL, "has-thumbnail");
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_THUMBNAIL_PATH, "thumbnail-path");
	g_object_class_install_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_URI, g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_MATCH_TYPE, "match-type");
}


static void synapse_test_slow_plugin_test_result_synapse_match_interface_init (SynapseMatchIface * iface) {
	synapse_test_slow_plugin_test_result_synapse_match_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_title = synapse_test_slow_plugin_test_result_real_get_title;
	iface->set_title = synapse_test_slow_plugin_test_result_real_set_title;
	iface->get_description = synapse_test_slow_plugin_test_result_real_get_description;
	iface->set_description = synapse_test_slow_plugin_test_result_real_set_description;
	iface->get_icon_name = synapse_test_slow_plugin_test_result_real_get_icon_name;
	iface->set_icon_name = synapse_test_slow_plugin_test_result_real_set_icon_name;
	iface->get_has_thumbnail = synapse_test_slow_plugin_test_result_real_get_has_thumbnail;
	iface->set_has_thumbnail = synapse_test_slow_plugin_test_result_real_set_has_thumbnail;
	iface->get_thumbnail_path = synapse_test_slow_plugin_test_result_real_get_thumbnail_path;
	iface->set_thumbnail_path = synapse_test_slow_plugin_test_result_real_set_thumbnail_path;
	iface->get_match_type = synapse_test_slow_plugin_test_result_real_get_match_type;
	iface->set_match_type = synapse_test_slow_plugin_test_result_real_set_match_type;
}


static void synapse_test_slow_plugin_test_result_instance_init (SynapseTestSlowPluginTestResult * self) {
	self->priv = SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_GET_PRIVATE (self);
	self->priv->_description = g_strdup ("");
	self->priv->_icon_name = g_strdup ("");
	self->priv->_has_thumbnail = FALSE;
}


static void synapse_test_slow_plugin_test_result_finalize (GObject* obj) {
	SynapseTestSlowPluginTestResult * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT (obj);
	_g_free0 (self->priv->_title);
	_g_free0 (self->priv->_description);
	_g_free0 (self->priv->_icon_name);
	_g_free0 (self->priv->_thumbnail_path);
	_g_free0 (self->priv->_uri);
	G_OBJECT_CLASS (synapse_test_slow_plugin_test_result_parent_class)->finalize (obj);
}


static GType synapse_test_slow_plugin_test_result_get_type (void) {
	static volatile gsize synapse_test_slow_plugin_test_result_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_test_slow_plugin_test_result_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SynapseTestSlowPluginTestResultClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) synapse_test_slow_plugin_test_result_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SynapseTestSlowPluginTestResult), 0, (GInstanceInitFunc) synapse_test_slow_plugin_test_result_instance_init, NULL };
		static const GInterfaceInfo synapse_match_info = { (GInterfaceInitFunc) synapse_test_slow_plugin_test_result_synapse_match_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType synapse_test_slow_plugin_test_result_type_id;
		synapse_test_slow_plugin_test_result_type_id = g_type_register_static (G_TYPE_OBJECT, "SynapseTestSlowPluginTestResult", &g_define_type_info, 0);
		g_type_add_interface_static (synapse_test_slow_plugin_test_result_type_id, SYNAPSE_TYPE_MATCH, &synapse_match_info);
		g_once_init_leave (&synapse_test_slow_plugin_test_result_type_id__volatile, synapse_test_slow_plugin_test_result_type_id);
	}
	return synapse_test_slow_plugin_test_result_type_id__volatile;
}


static void synapse_test_slow_plugin_test_result_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SynapseTestSlowPluginTestResult * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT (object);
	switch (property_id) {
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_TITLE:
		g_value_set_string (value, synapse_match_get_title ((SynapseMatch*) self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_DESCRIPTION:
		g_value_set_string (value, synapse_match_get_description ((SynapseMatch*) self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_ICON_NAME:
		g_value_set_string (value, synapse_match_get_icon_name ((SynapseMatch*) self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_HAS_THUMBNAIL:
		g_value_set_boolean (value, synapse_match_get_has_thumbnail ((SynapseMatch*) self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_THUMBNAIL_PATH:
		g_value_set_string (value, synapse_match_get_thumbnail_path ((SynapseMatch*) self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_URI:
		g_value_set_string (value, synapse_test_slow_plugin_test_result_get_uri (self));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_MATCH_TYPE:
		g_value_set_enum (value, synapse_match_get_match_type ((SynapseMatch*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void synapse_test_slow_plugin_test_result_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SynapseTestSlowPluginTestResult * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT (object);
	switch (property_id) {
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_TITLE:
		synapse_match_set_title ((SynapseMatch*) self, g_value_get_string (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_DESCRIPTION:
		synapse_match_set_description ((SynapseMatch*) self, g_value_get_string (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_ICON_NAME:
		synapse_match_set_icon_name ((SynapseMatch*) self, g_value_get_string (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_HAS_THUMBNAIL:
		synapse_match_set_has_thumbnail ((SynapseMatch*) self, g_value_get_boolean (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_THUMBNAIL_PATH:
		synapse_match_set_thumbnail_path ((SynapseMatch*) self, g_value_get_string (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_URI:
		synapse_test_slow_plugin_test_result_set_uri (self, g_value_get_string (value));
		break;
		case SYNAPSE_TEST_SLOW_PLUGIN_TEST_RESULT_MATCH_TYPE:
		synapse_match_set_match_type ((SynapseMatch*) self, g_value_get_enum (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void synapse_test_slow_plugin_class_init (SynapseTestSlowPluginClass * klass) {
	synapse_test_slow_plugin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SynapseTestSlowPluginPrivate));
	G_OBJECT_CLASS (klass)->get_property = synapse_test_slow_plugin_get_property;
	G_OBJECT_CLASS (klass)->set_property = synapse_test_slow_plugin_set_property;
	G_OBJECT_CLASS (klass)->finalize = synapse_test_slow_plugin_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_TEST_SLOW_PLUGIN_ENABLED, "enabled");
}


static void synapse_test_slow_plugin_synapse_activatable_interface_init (SynapseActivatableIface * iface) {
	synapse_test_slow_plugin_synapse_activatable_parent_iface = g_type_interface_peek_parent (iface);
	iface->activate = synapse_test_slow_plugin_real_activate;
	iface->deactivate = synapse_test_slow_plugin_real_deactivate;
	iface->get_enabled = synapse_test_slow_plugin_real_get_enabled;
	iface->set_enabled = synapse_test_slow_plugin_real_set_enabled;
}


static void synapse_test_slow_plugin_synapse_item_provider_interface_init (SynapseItemProviderIface * iface) {
	synapse_test_slow_plugin_synapse_item_provider_parent_iface = g_type_interface_peek_parent (iface);
	iface->search = synapse_test_slow_plugin_real_search;
	iface->search_finish = synapse_test_slow_plugin_real_search_finish;
}


static void synapse_test_slow_plugin_instance_init (SynapseTestSlowPlugin * self) {
	self->priv = SYNAPSE_TEST_SLOW_PLUGIN_GET_PRIVATE (self);
	self->priv->_enabled = TRUE;
}


static void synapse_test_slow_plugin_finalize (GObject* obj) {
	SynapseTestSlowPlugin * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN (obj);
	G_OBJECT_CLASS (synapse_test_slow_plugin_parent_class)->finalize (obj);
}


GType synapse_test_slow_plugin_get_type (void) {
	static volatile gsize synapse_test_slow_plugin_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_test_slow_plugin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SynapseTestSlowPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) synapse_test_slow_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SynapseTestSlowPlugin), 0, (GInstanceInitFunc) synapse_test_slow_plugin_instance_init, NULL };
		static const GInterfaceInfo synapse_activatable_info = { (GInterfaceInitFunc) synapse_test_slow_plugin_synapse_activatable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		static const GInterfaceInfo synapse_item_provider_info = { (GInterfaceInitFunc) synapse_test_slow_plugin_synapse_item_provider_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType synapse_test_slow_plugin_type_id;
		synapse_test_slow_plugin_type_id = g_type_register_static (G_TYPE_OBJECT, "SynapseTestSlowPlugin", &g_define_type_info, 0);
		g_type_add_interface_static (synapse_test_slow_plugin_type_id, SYNAPSE_TYPE_ACTIVATABLE, &synapse_activatable_info);
		g_type_add_interface_static (synapse_test_slow_plugin_type_id, SYNAPSE_TYPE_ITEM_PROVIDER, &synapse_item_provider_info);
		g_once_init_leave (&synapse_test_slow_plugin_type_id__volatile, synapse_test_slow_plugin_type_id);
	}
	return synapse_test_slow_plugin_type_id__volatile;
}


static void synapse_test_slow_plugin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SynapseTestSlowPlugin * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN (object);
	switch (property_id) {
		case SYNAPSE_TEST_SLOW_PLUGIN_ENABLED:
		g_value_set_boolean (value, synapse_activatable_get_enabled ((SynapseActivatable*) self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void synapse_test_slow_plugin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SynapseTestSlowPlugin * self;
	self = SYNAPSE_TEST_SLOW_PLUGIN (object);
	switch (property_id) {
		case SYNAPSE_TEST_SLOW_PLUGIN_ENABLED:
		synapse_activatable_set_enabled ((SynapseActivatable*) self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




