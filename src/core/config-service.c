/* config-service.c generated by valac 0.10.4, the Vala compiler
 * generated from config-service.vala, do not modify */

/*
 * Copyright (C) 2010 Michal Hruby <michal.mhr@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by Michal Hruby <michal.mhr@gmail.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include <stdlib.h>
#include <string.h>


#define SYNAPSE_TYPE_CONFIG_OBJECT (synapse_config_object_get_type ())
#define SYNAPSE_CONFIG_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_CONFIG_OBJECT, SynapseConfigObject))
#define SYNAPSE_CONFIG_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYNAPSE_TYPE_CONFIG_OBJECT, SynapseConfigObjectClass))
#define SYNAPSE_IS_CONFIG_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_CONFIG_OBJECT))
#define SYNAPSE_IS_CONFIG_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYNAPSE_TYPE_CONFIG_OBJECT))
#define SYNAPSE_CONFIG_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYNAPSE_TYPE_CONFIG_OBJECT, SynapseConfigObjectClass))

typedef struct _SynapseConfigObject SynapseConfigObject;
typedef struct _SynapseConfigObjectClass SynapseConfigObjectClass;
typedef struct _SynapseConfigObjectPrivate SynapseConfigObjectPrivate;

#define SYNAPSE_TYPE_CONFIG_SERVICE (synapse_config_service_get_type ())
#define SYNAPSE_CONFIG_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_CONFIG_SERVICE, SynapseConfigService))
#define SYNAPSE_CONFIG_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYNAPSE_TYPE_CONFIG_SERVICE, SynapseConfigServiceClass))
#define SYNAPSE_IS_CONFIG_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_CONFIG_SERVICE))
#define SYNAPSE_IS_CONFIG_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYNAPSE_TYPE_CONFIG_SERVICE))
#define SYNAPSE_CONFIG_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYNAPSE_TYPE_CONFIG_SERVICE, SynapseConfigServiceClass))

typedef struct _SynapseConfigService SynapseConfigService;
typedef struct _SynapseConfigServiceClass SynapseConfigServiceClass;
typedef struct _SynapseConfigServicePrivate SynapseConfigServicePrivate;
#define _json_node_free0(var) ((var == NULL) ? NULL : (var = (json_node_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _SynapseConfigObject {
	GObject parent_instance;
	SynapseConfigObjectPrivate * priv;
};

struct _SynapseConfigObjectClass {
	GObjectClass parent_class;
};

struct _SynapseConfigService {
	GObject parent_instance;
	SynapseConfigServicePrivate * priv;
};

struct _SynapseConfigServiceClass {
	GObjectClass parent_class;
};

struct _SynapseConfigServicePrivate {
	JsonNode* root_node;
	char* config_file_name;
	guint save_timer_id;
};

struct _Block1Data {
	int _ref_count_;
	SynapseConfigService * self;
	SynapseConfigObject* co;
	char* group;
	char* key;
};


static gpointer synapse_config_object_parent_class = NULL;
static SynapseConfigService* synapse_config_service_instance;
static SynapseConfigService* synapse_config_service_instance = NULL;
static gpointer synapse_config_service_parent_class = NULL;

GType synapse_config_object_get_type (void) G_GNUC_CONST;
enum  {
	SYNAPSE_CONFIG_OBJECT_DUMMY_PROPERTY
};
SynapseConfigObject* synapse_config_object_construct (GType object_type);
GType synapse_config_service_get_type (void) G_GNUC_CONST;
#define SYNAPSE_CONFIG_SERVICE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SYNAPSE_TYPE_CONFIG_SERVICE, SynapseConfigServicePrivate))
enum  {
	SYNAPSE_CONFIG_SERVICE_DUMMY_PROPERTY
};
SynapseConfigService* synapse_config_service_get_default (void);
static SynapseConfigService* synapse_config_service_new (void);
static SynapseConfigService* synapse_config_service_construct (GType object_type);
SynapseConfigObject* synapse_config_service_get_config (SynapseConfigService* self, const char* group, const char* key, GType config_type);
SynapseConfigObject* synapse_config_service_bind_config (SynapseConfigService* self, const char* group, const char* key, GType config_type);
static void _lambda3_ (Block1Data* _data1_);
void synapse_config_service_set_config (SynapseConfigService* self, const char* group, const char* key, SynapseConfigObject* cfg_obj);
static void __lambda3__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (Block1Data* _data1_);
static gboolean synapse_config_service_save_timeout (SynapseConfigService* self);
static gboolean _synapse_config_service_save_timeout_gsource_func (gpointer self);
void synapse_config_service_save (SynapseConfigService* self);
static GObject * synapse_config_service_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void synapse_config_service_finalize (GObject* obj);



SynapseConfigObject* synapse_config_object_construct (GType object_type) {
	SynapseConfigObject * self = NULL;
	self = (SynapseConfigObject*) g_object_new (object_type, NULL);
	return self;
}


static void synapse_config_object_class_init (SynapseConfigObjectClass * klass) {
	synapse_config_object_parent_class = g_type_class_peek_parent (klass);
}


static void synapse_config_object_instance_init (SynapseConfigObject * self) {
}


GType synapse_config_object_get_type (void) {
	static volatile gsize synapse_config_object_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_config_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SynapseConfigObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) synapse_config_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SynapseConfigObject), 0, (GInstanceInitFunc) synapse_config_object_instance_init, NULL };
		GType synapse_config_object_type_id;
		synapse_config_object_type_id = g_type_register_static (G_TYPE_OBJECT, "SynapseConfigObject", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&synapse_config_object_type_id__volatile, synapse_config_object_type_id);
	}
	return synapse_config_object_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


SynapseConfigService* synapse_config_service_get_default (void) {
	SynapseConfigService* result = NULL;
	SynapseConfigService* _tmp0_;
	_tmp0_ = _g_object_ref0 (synapse_config_service_instance);
	if (_tmp0_ == NULL) {
		SynapseConfigService* _tmp1_;
		_tmp0_ = (_tmp1_ = synapse_config_service_new (), _g_object_unref0 (_tmp0_), _tmp1_);
	}
	result = _tmp0_;
	return result;
}


static SynapseConfigService* synapse_config_service_construct (GType object_type) {
	SynapseConfigService * self = NULL;
	self = (SynapseConfigService*) g_object_new (object_type, NULL);
	return self;
}


static SynapseConfigService* synapse_config_service_new (void) {
	return synapse_config_service_construct (SYNAPSE_TYPE_CONFIG_SERVICE);
}


/**
     * Creates an instance of an object derived from ConfigObject class, which
     * will have its public properties set to values stored in config file, or
     * to the default values if this object wasn't yet stored.
     *
     * @param group A group name.
     * @param key A key name.
     * @param config_type Type of the object (must be subclass of ConfigObject)
     * @return An instance of config_type.
     */
SynapseConfigObject* synapse_config_service_get_config (SynapseConfigService* self, const char* group, const char* key, GType config_type) {
	SynapseConfigObject* result = NULL;
	JsonObject* obj;
	JsonNode* group_node;
	GObject* _tmp2_;
	GObject* _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (group != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	obj = json_node_get_object (self->priv->root_node);
	group_node = json_object_get_member (obj, group);
	if (group_node != NULL) {
		if (json_node_get_node_type (group_node) == JSON_NODE_OBJECT) {
			JsonObject* group_obj;
			JsonNode* key_node;
			gboolean _tmp0_ = FALSE;
			group_obj = json_node_get_object (group_node);
			key_node = json_object_get_member (group_obj, key);
			if (key_node != NULL) {
				_tmp0_ = json_node_get_node_type (key_node) == JSON_NODE_OBJECT;
			} else {
				_tmp0_ = FALSE;
			}
			if (_tmp0_) {
				GObject* _result_;
				GObject* _tmp1_;
				_result_ = _g_object_ref0 (json_gobject_deserialize (config_type, key_node));
				result = _g_object_ref0 ((_tmp1_ = _result_, SYNAPSE_IS_CONFIG_OBJECT (_tmp1_) ? ((SynapseConfigObject*) _tmp1_) : NULL));
				_g_object_unref0 (_result_);
				return result;
				_g_object_unref0 (_result_);
			}
		}
	}
	result = (_tmp3_ = (_tmp2_ = g_object_new (config_type, NULL), G_IS_INITIALLY_UNOWNED (_tmp2_) ? g_object_ref_sink (_tmp2_) : _tmp2_), SYNAPSE_IS_CONFIG_OBJECT (_tmp3_) ? ((SynapseConfigObject*) _tmp3_) : NULL);
	return result;
}


/**
     * Behaves in a similar way to get_config, but it also watches for changes
     * in the returned config object and saves them back to the config file
     * (without the need of calling set_config).
     *
     * @param group A group name.
     * @param key A key name.
     * @param config_type Type of the object (must be subclass of ConfigObject)
     */
static void _lambda3_ (Block1Data* _data1_) {
	SynapseConfigService * self;
	self = _data1_->self;
	synapse_config_service_set_config (self, _data1_->group, _data1_->key, _data1_->co);
}


static void __lambda3__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	_lambda3_ (self);
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (Block1Data* _data1_) {
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->self);
		_g_free0 (_data1_->group);
		_g_free0 (_data1_->key);
		g_slice_free (Block1Data, _data1_);
	}
}


SynapseConfigObject* synapse_config_service_bind_config (SynapseConfigService* self, const char* group, const char* key, GType config_type) {
	SynapseConfigObject* result = NULL;
	Block1Data* _data1_;
	SynapseConfigObject* config_object;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (group != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = g_object_ref (self);
	_data1_->group = g_strdup (group);
	_data1_->key = g_strdup (key);
	config_object = synapse_config_service_get_config (self, _data1_->group, _data1_->key, config_type);
	_data1_->co = config_object;
	g_signal_connect_data ((GObject*) _data1_->co, "notify", (GCallback) __lambda3__g_object_notify, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	result = config_object;
	block1_data_unref (_data1_);
	return result;
}


/**
     * Stores all public properties of the object to the config file under
     * specified group and key names.
     *
     * @param group A group name.
     * @param key A key name.
     * @param cfg_obj ConfigObject instance.
     */
static gpointer _json_object_ref0 (gpointer self) {
	return self ? json_object_ref (self) : NULL;
}


static gboolean _synapse_config_service_save_timeout_gsource_func (gpointer self) {
	gboolean result;
	result = synapse_config_service_save_timeout (self);
	return result;
}


void synapse_config_service_set_config (SynapseConfigService* self, const char* group, const char* key, SynapseConfigObject* cfg_obj) {
	JsonObject* obj;
	gboolean _tmp0_ = FALSE;
	JsonObject* group_obj;
	JsonNode* node;
	g_return_if_fail (self != NULL);
	g_return_if_fail (group != NULL);
	g_return_if_fail (key != NULL);
	g_return_if_fail (cfg_obj != NULL);
	obj = json_node_get_object (self->priv->root_node);
	if (!json_object_has_member (obj, group)) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = json_node_get_node_type (json_object_get_member (obj, group)) != JSON_NODE_OBJECT;
	}
	if (_tmp0_) {
		json_object_set_object_member (obj, group, json_object_new ());
	}
	group_obj = json_object_get_object_member (obj, group);
	if (json_object_has_member (group_obj, key)) {
		json_object_remove_member (group_obj, key);
	}
	node = json_gobject_serialize ((GObject*) cfg_obj);
	json_object_set_object_member (group_obj, key, _json_object_ref0 (json_node_get_object (node)));
	if (self->priv->save_timer_id != 0) {
		g_source_remove (self->priv->save_timer_id);
	}
	self->priv->save_timer_id = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 30000, _synapse_config_service_save_timeout_gsource_func, g_object_ref (self), g_object_unref);
}


static gboolean synapse_config_service_save_timeout (SynapseConfigService* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	self->priv->save_timer_id = (guint) 0;
	synapse_config_service_save (self);
	result = FALSE;
	return result;
}


/**
     * Forces immediate saving of the configuration file to the filesystem.
     */
void synapse_config_service_save (SynapseConfigService* self) {
	JsonGenerator* generator;
	char* _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	if (self->priv->save_timer_id != 0) {
		g_source_remove (self->priv->save_timer_id);
		self->priv->save_timer_id = (guint) 0;
	}
	generator = json_generator_new ();
	g_object_set (generator, "pretty", TRUE, NULL);
	json_generator_set_root (generator, self->priv->root_node);
	g_mkdir_with_parents (_tmp0_ = g_path_get_dirname (self->priv->config_file_name), 0755);
	_g_free0 (_tmp0_);
	json_generator_to_file (generator, self->priv->config_file_name, &_inner_error_);
	if (_inner_error_ != NULL) {
		_g_object_unref0 (generator);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (generator);
}


static GObject * synapse_config_service_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	SynapseConfigService * self;
	GError * _inner_error_;
	parent_class = G_OBJECT_CLASS (synapse_config_service_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = SYNAPSE_CONFIG_SERVICE (obj);
	_inner_error_ = NULL;
	{
		JsonParser* parser;
		char* _tmp0_;
		synapse_config_service_instance = self;
		parser = json_parser_new ();
		self->priv->config_file_name = (_tmp0_ = g_build_filename (g_get_user_config_dir (), "synapse", "config.json", NULL), _g_free0 (self->priv->config_file_name), _tmp0_);
		{
			JsonNode* _tmp1_;
			json_parser_load_from_file (parser, self->priv->config_file_name, &_inner_error_);
			if (_inner_error_ != NULL) {
				goto __catch5_g_error;
			}
			self->priv->root_node = (_tmp1_ = json_node_copy (json_parser_get_root (parser)), _json_node_free0 (self->priv->root_node), _tmp1_);
			if (json_node_get_node_type (self->priv->root_node) != JSON_NODE_OBJECT) {
				JsonNode* _tmp2_;
				self->priv->root_node = (_tmp2_ = json_node_new (JSON_NODE_OBJECT), _json_node_free0 (self->priv->root_node), _tmp2_);
				json_node_take_object (self->priv->root_node, json_object_new ());
			}
		}
		goto __finally5;
		__catch5_g_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				JsonNode* _tmp3_;
				self->priv->root_node = (_tmp3_ = json_node_new (JSON_NODE_OBJECT), _json_node_free0 (self->priv->root_node), _tmp3_);
				json_node_take_object (self->priv->root_node, json_object_new ());
				_g_error_free0 (err);
			}
		}
		__finally5:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (parser);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
		}
		_g_object_unref0 (parser);
	}
	return obj;
}


static void synapse_config_service_class_init (SynapseConfigServiceClass * klass) {
	synapse_config_service_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SynapseConfigServicePrivate));
	G_OBJECT_CLASS (klass)->constructor = synapse_config_service_constructor;
	G_OBJECT_CLASS (klass)->finalize = synapse_config_service_finalize;
}


static void synapse_config_service_instance_init (SynapseConfigService * self) {
	self->priv = SYNAPSE_CONFIG_SERVICE_GET_PRIVATE (self);
	self->priv->save_timer_id = (guint) 0;
}


static void synapse_config_service_finalize (GObject* obj) {
	SynapseConfigService * self;
	self = SYNAPSE_CONFIG_SERVICE (obj);
	{
		if (self->priv->save_timer_id != 0) {
			synapse_config_service_save (self);
		}
		synapse_config_service_instance = NULL;
	}
	_json_node_free0 (self->priv->root_node);
	_g_free0 (self->priv->config_file_name);
	G_OBJECT_CLASS (synapse_config_service_parent_class)->finalize (obj);
}


GType synapse_config_service_get_type (void) {
	static volatile gsize synapse_config_service_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_config_service_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SynapseConfigServiceClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) synapse_config_service_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SynapseConfigService), 0, (GInstanceInitFunc) synapse_config_service_instance_init, NULL };
		GType synapse_config_service_type_id;
		synapse_config_service_type_id = g_type_register_static (G_TYPE_OBJECT, "SynapseConfigService", &g_define_type_info, 0);
		g_once_init_leave (&synapse_config_service_type_id__volatile, synapse_config_service_type_id);
	}
	return synapse_config_service_type_id__volatile;
}




