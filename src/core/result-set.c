/* result-set.c generated by valac 0.10.4, the Vala compiler
 * generated from result-set.vala, do not modify */

/*
 * Copyright (C) 2010 Michal Hruby <michal.mhr@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
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
#include <gee.h>
#include <stdlib.h>
#include <string.h>


#define SYNAPSE_TYPE_RESULT_SET (synapse_result_set_get_type ())
#define SYNAPSE_RESULT_SET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_RESULT_SET, SynapseResultSet))
#define SYNAPSE_RESULT_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYNAPSE_TYPE_RESULT_SET, SynapseResultSetClass))
#define SYNAPSE_IS_RESULT_SET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_RESULT_SET))
#define SYNAPSE_IS_RESULT_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYNAPSE_TYPE_RESULT_SET))
#define SYNAPSE_RESULT_SET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYNAPSE_TYPE_RESULT_SET, SynapseResultSetClass))

typedef struct _SynapseResultSet SynapseResultSet;
typedef struct _SynapseResultSetClass SynapseResultSetClass;
typedef struct _SynapseResultSetPrivate SynapseResultSetPrivate;

#define SYNAPSE_TYPE_MATCH (synapse_match_get_type ())
#define SYNAPSE_MATCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_MATCH, SynapseMatch))
#define SYNAPSE_IS_MATCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_MATCH))
#define SYNAPSE_MATCH_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SYNAPSE_TYPE_MATCH, SynapseMatchIface))

typedef struct _SynapseMatch SynapseMatch;
typedef struct _SynapseMatchIface SynapseMatchIface;

#define SYNAPSE_TYPE_MATCH_TYPE (synapse_match_type_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SYNAPSE_TYPE_URI_MATCH (synapse_uri_match_get_type ())
#define SYNAPSE_URI_MATCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYNAPSE_TYPE_URI_MATCH, SynapseUriMatch))
#define SYNAPSE_IS_URI_MATCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYNAPSE_TYPE_URI_MATCH))
#define SYNAPSE_URI_MATCH_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SYNAPSE_TYPE_URI_MATCH, SynapseUriMatchIface))

typedef struct _SynapseUriMatch SynapseUriMatch;
typedef struct _SynapseUriMatchIface SynapseUriMatchIface;

#define SYNAPSE_TYPE_QUERY_FLAGS (synapse_query_flags_get_type ())

typedef enum  {
	SYNAPSE_MATCH_TYPE_UNKNOWN = 0,
	SYNAPSE_MATCH_TYPE_TEXT,
	SYNAPSE_MATCH_TYPE_APPLICATION,
	SYNAPSE_MATCH_TYPE_GENERIC_URI,
	SYNAPSE_MATCH_TYPE_ACTION,
	SYNAPSE_MATCH_TYPE_SEARCH
} SynapseMatchType;

struct _SynapseMatchIface {
	GTypeInterface parent_iface;
	void (*execute) (SynapseMatch* self, SynapseMatch* match);
	const char* (*get_title) (SynapseMatch* self);
	void (*set_title) (SynapseMatch* self, const char* value);
	const char* (*get_description) (SynapseMatch* self);
	void (*set_description) (SynapseMatch* self, const char* value);
	const char* (*get_icon_name) (SynapseMatch* self);
	void (*set_icon_name) (SynapseMatch* self, const char* value);
	gboolean (*get_has_thumbnail) (SynapseMatch* self);
	void (*set_has_thumbnail) (SynapseMatch* self, gboolean value);
	const char* (*get_thumbnail_path) (SynapseMatch* self);
	void (*set_thumbnail_path) (SynapseMatch* self, const char* value);
	SynapseMatchType (*get_match_type) (SynapseMatch* self);
	void (*set_match_type) (SynapseMatch* self, SynapseMatchType value);
};

struct _SynapseResultSet {
	GObject parent_instance;
	SynapseResultSetPrivate * priv;
	GeeMap* matches;
	GeeSet* uris;
};

struct _SynapseResultSetClass {
	GObjectClass parent_class;
};

typedef enum  {
	SYNAPSE_QUERY_FLAGS_INCLUDE_REMOTE = 1 << 0,
	SYNAPSE_QUERY_FLAGS_APPLICATIONS = 1 << 1,
	SYNAPSE_QUERY_FLAGS_ACTIONS = 1 << 2,
	SYNAPSE_QUERY_FLAGS_AUDIO = 1 << 3,
	SYNAPSE_QUERY_FLAGS_VIDEO = 1 << 4,
	SYNAPSE_QUERY_FLAGS_DOCUMENTS = 1 << 5,
	SYNAPSE_QUERY_FLAGS_IMAGES = 1 << 6,
	SYNAPSE_QUERY_FLAGS_INTERNET = 1 << 7,
	SYNAPSE_QUERY_FLAGS_UNCATEGORIZED = 1 << 15,
	SYNAPSE_QUERY_FLAGS_ALL = 0xFF | SYNAPSE_QUERY_FLAGS_UNCATEGORIZED,
	SYNAPSE_QUERY_FLAGS_LOCAL_CONTENT = SYNAPSE_QUERY_FLAGS_ALL ^ SYNAPSE_QUERY_FLAGS_INCLUDE_REMOTE
} SynapseQueryFlags;

struct _SynapseUriMatchIface {
	GTypeInterface parent_iface;
	const char* (*get_uri) (SynapseUriMatch* self);
	void (*set_uri) (SynapseUriMatch* self, const char* value);
	SynapseQueryFlags (*get_file_type) (SynapseUriMatch* self);
	void (*set_file_type) (SynapseUriMatch* self, SynapseQueryFlags value);
	const char* (*get_mime_type) (SynapseUriMatch* self);
	void (*set_mime_type) (SynapseUriMatch* self, const char* value);
};


static gpointer synapse_result_set_parent_class = NULL;
static GeeIterableIface* synapse_result_set_gee_iterable_parent_iface = NULL;

GType synapse_result_set_get_type (void) G_GNUC_CONST;
GType synapse_match_type_get_type (void) G_GNUC_CONST;
GType synapse_match_get_type (void) G_GNUC_CONST;
enum  {
	SYNAPSE_RESULT_SET_DUMMY_PROPERTY,
	SYNAPSE_RESULT_SET_ELEMENT_TYPE,
	SYNAPSE_RESULT_SET_SIZE,
	SYNAPSE_RESULT_SET_KEYS,
	SYNAPSE_RESULT_SET_ENTRIES
};
SynapseResultSet* synapse_result_set_new (void);
SynapseResultSet* synapse_result_set_construct (GType object_type);
static GeeIterator* synapse_result_set_real_iterator (GeeIterable* base);
void synapse_result_set_add (SynapseResultSet* self, SynapseMatch* match, gint relevancy);
GType synapse_query_flags_get_type (void) G_GNUC_CONST;
GType synapse_uri_match_get_type (void) G_GNUC_CONST;
const char* synapse_uri_match_get_uri (SynapseUriMatch* self);
void synapse_result_set_add_all (SynapseResultSet* self, SynapseResultSet* rs);
gboolean synapse_result_set_contains_uri (SynapseResultSet* self, const char* uri);
GeeList* synapse_result_set_get_sorted_list (SynapseResultSet* self);
static gint _lambda0_ (void* a, void* b, SynapseResultSet* self);
const char* synapse_match_get_title (SynapseMatch* self);
static gint __lambda0__gcompare_data_func (void* a, void* b, gpointer self);
gint synapse_result_set_get_size (SynapseResultSet* self);
GeeSet* synapse_result_set_get_keys (SynapseResultSet* self);
GeeSet* synapse_result_set_get_entries (SynapseResultSet* self);
static GObject * synapse_result_set_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void synapse_result_set_finalize (GObject* obj);
static void synapse_result_set_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



SynapseResultSet* synapse_result_set_construct (GType object_type) {
	SynapseResultSet * self = NULL;
	self = (SynapseResultSet*) g_object_new (object_type, NULL);
	return self;
}


SynapseResultSet* synapse_result_set_new (void) {
	return synapse_result_set_construct (SYNAPSE_TYPE_RESULT_SET);
}


static GeeIterator* synapse_result_set_real_iterator (GeeIterable* base) {
	SynapseResultSet * self;
	GeeIterator* result = NULL;
	self = (SynapseResultSet*) base;
	result = gee_iterable_iterator ((GeeIterable*) self->matches);
	return result;
}


void synapse_result_set_add (SynapseResultSet* self, SynapseMatch* match, gint relevancy) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (match != NULL);
	gee_map_set (self->matches, match, GINT_TO_POINTER (relevancy));
	if (SYNAPSE_IS_URI_MATCH (match)) {
		SynapseMatch* _tmp0_;
		const char* uri;
		gboolean _tmp1_ = FALSE;
		uri = synapse_uri_match_get_uri ((_tmp0_ = match, SYNAPSE_IS_URI_MATCH (_tmp0_) ? ((SynapseUriMatch*) _tmp0_) : NULL));
		if (uri != NULL) {
			_tmp1_ = _vala_strcmp0 (uri, "") != 0;
		} else {
			_tmp1_ = FALSE;
		}
		if (_tmp1_) {
			gee_collection_add ((GeeCollection*) self->uris, uri);
		}
	}
}


void synapse_result_set_add_all (SynapseResultSet* self, SynapseResultSet* rs) {
	g_return_if_fail (self != NULL);
	if (rs == NULL) {
		return;
	}
	gee_map_set_all (self->matches, rs->matches);
	gee_collection_add_all ((GeeCollection*) self->uris, (GeeCollection*) rs->uris);
}


gboolean synapse_result_set_contains_uri (SynapseResultSet* self, const char* uri) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (uri != NULL, FALSE);
	result = gee_collection_contains ((GeeCollection*) self->uris, uri);
	return result;
}


static gint _lambda0_ (void* a, void* b, SynapseResultSet* self) {
	gint result = 0;
	GeeMapEntry* e1;
	GeeMapEntry* e2;
	gint relevancy_delta;
	e1 = GEE_MAP_ENTRY (a);
	e2 = GEE_MAP_ENTRY (b);
	relevancy_delta = GPOINTER_TO_INT (gee_map_entry_get_value (e2)) - GPOINTER_TO_INT (gee_map_entry_get_value (e1));
	if (relevancy_delta != 0) {
		result = relevancy_delta;
		return result;
	} else {
		result = g_ascii_strcasecmp (synapse_match_get_title ((SynapseMatch*) gee_map_entry_get_key (e1)), synapse_match_get_title ((SynapseMatch*) gee_map_entry_get_key (e2)));
		return result;
	}
}


static gint __lambda0__gcompare_data_func (void* a, void* b, gpointer self) {
	gint result;
	result = _lambda0_ (a, b, self);
	return result;
}


GeeList* synapse_result_set_get_sorted_list (SynapseResultSet* self) {
	GeeList* result = NULL;
	GeeArrayList* l;
	GeeSet* _tmp0_;
	GeeArrayList* sorted_list;
	g_return_val_if_fail (self != NULL, NULL);
	l = gee_array_list_new (GEE_MAP_TYPE_ENTRY, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	gee_abstract_collection_add_all ((GeeAbstractCollection*) l, (GeeCollection*) (_tmp0_ = gee_map_get_entries (self->matches)));
	_g_object_unref0 (_tmp0_);
	gee_list_sort ((GeeList*) l, __lambda0__gcompare_data_func, g_object_ref (self), g_object_unref);
	sorted_list = gee_array_list_new (SYNAPSE_TYPE_MATCH, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	{
		GeeIterator* _m_it;
		_m_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) l);
		while (TRUE) {
			GeeMapEntry* m;
			if (!gee_iterator_next (_m_it)) {
				break;
			}
			m = (GeeMapEntry*) gee_iterator_get (_m_it);
			gee_abstract_collection_add ((GeeAbstractCollection*) sorted_list, (SynapseMatch*) gee_map_entry_get_key (m));
			_g_object_unref0 (m);
		}
		_g_object_unref0 (_m_it);
	}
	result = (GeeList*) sorted_list;
	_g_object_unref0 (l);
	return result;
}


static GType synapse_result_set_real_get_element_type (GeeIterable* base) {
	GType result;
	SynapseResultSet* self;
	self = (SynapseResultSet*) base;
	result = gee_iterable_get_element_type ((GeeIterable*) self->matches);
	return result;
}


gint synapse_result_set_get_size (SynapseResultSet* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = gee_map_get_size (self->matches);
	return result;
}


GeeSet* synapse_result_set_get_keys (SynapseResultSet* self) {
	GeeSet* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = gee_map_get_keys (self->matches);
	return result;
}


GeeSet* synapse_result_set_get_entries (SynapseResultSet* self) {
	GeeSet* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = gee_map_get_entries (self->matches);
	return result;
}


static GObject * synapse_result_set_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	SynapseResultSet * self;
	parent_class = G_OBJECT_CLASS (synapse_result_set_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = SYNAPSE_RESULT_SET (obj);
	{
		GeeMap* _tmp0_;
		GeeSet* _tmp1_;
		self->matches = (_tmp0_ = (GeeMap*) gee_hash_map_new (SYNAPSE_TYPE_MATCH, (GBoxedCopyFunc) g_object_ref, g_object_unref, G_TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL), _g_object_unref0 (self->matches), _tmp0_);
		self->uris = (_tmp1_ = (GeeSet*) gee_hash_set_new (G_TYPE_STRING, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL), _g_object_unref0 (self->uris), _tmp1_);
	}
	return obj;
}


static void synapse_result_set_class_init (SynapseResultSetClass * klass) {
	synapse_result_set_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->get_property = synapse_result_set_get_property;
	G_OBJECT_CLASS (klass)->constructor = synapse_result_set_constructor;
	G_OBJECT_CLASS (klass)->finalize = synapse_result_set_finalize;
	g_object_class_override_property (G_OBJECT_CLASS (klass), SYNAPSE_RESULT_SET_ELEMENT_TYPE, "element-type");
	g_object_class_install_property (G_OBJECT_CLASS (klass), SYNAPSE_RESULT_SET_SIZE, g_param_spec_int ("size", "size", "size", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SYNAPSE_RESULT_SET_KEYS, g_param_spec_object ("keys", "keys", "keys", GEE_TYPE_SET, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SYNAPSE_RESULT_SET_ENTRIES, g_param_spec_object ("entries", "entries", "entries", GEE_TYPE_SET, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void synapse_result_set_gee_iterable_interface_init (GeeIterableIface * iface) {
	synapse_result_set_gee_iterable_parent_iface = g_type_interface_peek_parent (iface);
	iface->iterator = synapse_result_set_real_iterator;
	iface->get_element_type = synapse_result_set_real_get_element_type;
}


static void synapse_result_set_instance_init (SynapseResultSet * self) {
}


static void synapse_result_set_finalize (GObject* obj) {
	SynapseResultSet * self;
	self = SYNAPSE_RESULT_SET (obj);
	_g_object_unref0 (self->matches);
	_g_object_unref0 (self->uris);
	G_OBJECT_CLASS (synapse_result_set_parent_class)->finalize (obj);
}


GType synapse_result_set_get_type (void) {
	static volatile gsize synapse_result_set_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_result_set_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SynapseResultSetClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) synapse_result_set_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SynapseResultSet), 0, (GInstanceInitFunc) synapse_result_set_instance_init, NULL };
		static const GInterfaceInfo gee_iterable_info = { (GInterfaceInitFunc) synapse_result_set_gee_iterable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType synapse_result_set_type_id;
		synapse_result_set_type_id = g_type_register_static (G_TYPE_OBJECT, "SynapseResultSet", &g_define_type_info, 0);
		g_type_add_interface_static (synapse_result_set_type_id, GEE_TYPE_ITERABLE, &gee_iterable_info);
		g_once_init_leave (&synapse_result_set_type_id__volatile, synapse_result_set_type_id);
	}
	return synapse_result_set_type_id__volatile;
}


static void synapse_result_set_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SynapseResultSet * self;
	self = SYNAPSE_RESULT_SET (object);
	switch (property_id) {
		case SYNAPSE_RESULT_SET_ELEMENT_TYPE:
		g_value_set_gtype (value, gee_iterable_get_element_type ((GeeIterable*) self));
		break;
		case SYNAPSE_RESULT_SET_SIZE:
		g_value_set_int (value, synapse_result_set_get_size (self));
		break;
		case SYNAPSE_RESULT_SET_KEYS:
		g_value_take_object (value, synapse_result_set_get_keys (self));
		break;
		case SYNAPSE_RESULT_SET_ENTRIES:
		g_value_take_object (value, synapse_result_set_get_entries (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




