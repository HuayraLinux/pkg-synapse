/* query.c generated by valac 0.10.4, the Vala compiler
 * generated from query.vala, do not modify */

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
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <gee.h>


#define SYNAPSE_TYPE_QUERY_FLAGS (synapse_query_flags_get_type ())

#define SYNAPSE_TYPE_MATCHER_FLAGS (synapse_matcher_flags_get_type ())

#define SYNAPSE_TYPE_QUERY (synapse_query_get_type ())
typedef struct _SynapseQuery SynapseQuery;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))

#define SYNAPSE_MATCH_TYPE_SCORE (synapse_match_score_get_type ())
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

typedef enum  {
	SYNAPSE_MATCHER_FLAGS_NO_REVERSED = 1 << 0,
	SYNAPSE_MATCHER_FLAGS_NO_SUBSTRING = 1 << 1,
	SYNAPSE_MATCHER_FLAGS_NO_PARTIAL = 1 << 2,
	SYNAPSE_MATCHER_FLAGS_NO_FUZZY = 1 << 3
} SynapseMatcherFlags;

struct _SynapseQuery {
	char* query_string;
	char* query_string_folded;
	GCancellable* cancellable;
	SynapseQueryFlags query_type;
	guint max_results;
	guint query_id;
};

typedef enum  {
	SYNAPSE_SEARCH_ERROR_SEARCH_CANCELLED,
	SYNAPSE_SEARCH_ERROR_UNKNOWN_ERROR
} SynapseSearchError;
#define SYNAPSE_SEARCH_ERROR synapse_search_error_quark ()
typedef enum  {
	SYNAPSE_MATCH_SCORE_INCREMENT_MINOR = 2000,
	SYNAPSE_MATCH_SCORE_INCREMENT_SMALL = 5000,
	SYNAPSE_MATCH_SCORE_INCREMENT_MEDIUM = 10000,
	SYNAPSE_MATCH_SCORE_INCREMENT_LARGE = 20000,
	SYNAPSE_MATCH_SCORE_URI_PENALTY = 15000,
	SYNAPSE_MATCH_SCORE_POOR = 50000,
	SYNAPSE_MATCH_SCORE_BELOW_AVERAGE = 60000,
	SYNAPSE_MATCH_SCORE_AVERAGE = 70000,
	SYNAPSE_MATCH_SCORE_ABOVE_AVERAGE = 75000,
	SYNAPSE_MATCH_SCORE_GOOD = 80000,
	SYNAPSE_MATCH_SCORE_VERY_GOOD = 85000,
	SYNAPSE_MATCH_SCORE_EXCELLENT = 90000,
	SYNAPSE_MATCH_SCORE_HIGHEST = 100000
} SynapseMatchScore;



GType synapse_query_flags_get_type (void) G_GNUC_CONST;
GType synapse_matcher_flags_get_type (void) G_GNUC_CONST;
GType synapse_query_get_type (void) G_GNUC_CONST;
SynapseQuery* synapse_query_dup (const SynapseQuery* self);
void synapse_query_free (SynapseQuery* self);
void synapse_query_copy (const SynapseQuery* self, SynapseQuery* dest);
void synapse_query_destroy (SynapseQuery* self);
void synapse_query_init (SynapseQuery *self, guint query_id, const char* query, SynapseQueryFlags flags, guint num_results);
gboolean synapse_query_is_cancelled (SynapseQuery *self);
GQuark synapse_search_error_quark (void);
void synapse_query_check_cancellable (SynapseQuery *self, GError** error);
GeeList* synapse_query_get_matchers_for_query (const char* query, SynapseMatcherFlags match_flags, GRegexCompileFlags flags);
GType synapse_match_score_get_type (void) G_GNUC_CONST;
static void _vala_array_add6 (char*** array, int* length, int* size, char* value);
static void _vala_array_add7 (char*** array, int* length, int* size, char* value);
static gint _lambda1_ (void* a, void* b);
static gint __lambda1__gcompare_data_func (void* a, void* b, gpointer self);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



GType synapse_query_flags_get_type (void) {
	static volatile gsize synapse_query_flags_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_query_flags_type_id__volatile)) {
		static const GFlagsValue values[] = {{SYNAPSE_QUERY_FLAGS_INCLUDE_REMOTE, "SYNAPSE_QUERY_FLAGS_INCLUDE_REMOTE", "include-remote"}, {SYNAPSE_QUERY_FLAGS_APPLICATIONS, "SYNAPSE_QUERY_FLAGS_APPLICATIONS", "applications"}, {SYNAPSE_QUERY_FLAGS_ACTIONS, "SYNAPSE_QUERY_FLAGS_ACTIONS", "actions"}, {SYNAPSE_QUERY_FLAGS_AUDIO, "SYNAPSE_QUERY_FLAGS_AUDIO", "audio"}, {SYNAPSE_QUERY_FLAGS_VIDEO, "SYNAPSE_QUERY_FLAGS_VIDEO", "video"}, {SYNAPSE_QUERY_FLAGS_DOCUMENTS, "SYNAPSE_QUERY_FLAGS_DOCUMENTS", "documents"}, {SYNAPSE_QUERY_FLAGS_IMAGES, "SYNAPSE_QUERY_FLAGS_IMAGES", "images"}, {SYNAPSE_QUERY_FLAGS_INTERNET, "SYNAPSE_QUERY_FLAGS_INTERNET", "internet"}, {SYNAPSE_QUERY_FLAGS_UNCATEGORIZED, "SYNAPSE_QUERY_FLAGS_UNCATEGORIZED", "uncategorized"}, {SYNAPSE_QUERY_FLAGS_ALL, "SYNAPSE_QUERY_FLAGS_ALL", "all"}, {SYNAPSE_QUERY_FLAGS_LOCAL_CONTENT, "SYNAPSE_QUERY_FLAGS_LOCAL_CONTENT", "local-content"}, {0, NULL, NULL}};
		GType synapse_query_flags_type_id;
		synapse_query_flags_type_id = g_flags_register_static ("SynapseQueryFlags", values);
		g_once_init_leave (&synapse_query_flags_type_id__volatile, synapse_query_flags_type_id);
	}
	return synapse_query_flags_type_id__volatile;
}


GType synapse_matcher_flags_get_type (void) {
	static volatile gsize synapse_matcher_flags_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_matcher_flags_type_id__volatile)) {
		static const GFlagsValue values[] = {{SYNAPSE_MATCHER_FLAGS_NO_REVERSED, "SYNAPSE_MATCHER_FLAGS_NO_REVERSED", "no-reversed"}, {SYNAPSE_MATCHER_FLAGS_NO_SUBSTRING, "SYNAPSE_MATCHER_FLAGS_NO_SUBSTRING", "no-substring"}, {SYNAPSE_MATCHER_FLAGS_NO_PARTIAL, "SYNAPSE_MATCHER_FLAGS_NO_PARTIAL", "no-partial"}, {SYNAPSE_MATCHER_FLAGS_NO_FUZZY, "SYNAPSE_MATCHER_FLAGS_NO_FUZZY", "no-fuzzy"}, {0, NULL, NULL}};
		GType synapse_matcher_flags_type_id;
		synapse_matcher_flags_type_id = g_flags_register_static ("SynapseMatcherFlags", values);
		g_once_init_leave (&synapse_matcher_flags_type_id__volatile, synapse_matcher_flags_type_id);
	}
	return synapse_matcher_flags_type_id__volatile;
}


void synapse_query_init (SynapseQuery *self, guint query_id, const char* query, SynapseQueryFlags flags, guint num_results) {
	char* _tmp0_;
	char* _tmp1_;
	g_return_if_fail (query != NULL);
	memset (self, 0, sizeof (SynapseQuery));
	(*self).query_id = query_id;
	(*self).query_string = (_tmp0_ = g_strdup (query), _g_free0 ((*self).query_string), _tmp0_);
	(*self).query_string_folded = (_tmp1_ = g_utf8_casefold (query, -1), _g_free0 ((*self).query_string_folded), _tmp1_);
	(*self).query_type = flags;
	(*self).max_results = num_results;
}


gboolean synapse_query_is_cancelled (SynapseQuery *self) {
	gboolean result = FALSE;
	result = g_cancellable_is_cancelled ((*self).cancellable);
	return result;
}


void synapse_query_check_cancellable (SynapseQuery *self, GError** error) {
	GError * _inner_error_ = NULL;
	if (g_cancellable_is_cancelled ((*self).cancellable)) {
		_inner_error_ = g_error_new_literal (SYNAPSE_SEARCH_ERROR, SYNAPSE_SEARCH_ERROR_SEARCH_CANCELLED, "Cancelled");
		{
			if (_inner_error_->domain == SYNAPSE_SEARCH_ERROR) {
				g_propagate_error (error, _inner_error_);
				return;
			} else {
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
		}
	}
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


static void _vala_array_add6 (char*** array, int* length, int* size, char* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (char*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static void _vala_array_add7 (char*** array, int* length, int* size, char* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (char*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gint _lambda1_ (void* a, void* b) {
	gint result = 0;
	GeeMapEntry* e1;
	GeeMapEntry* e2;
	e1 = GEE_MAP_ENTRY (a);
	e2 = GEE_MAP_ENTRY (b);
	result = GPOINTER_TO_INT (gee_map_entry_get_value (e2)) - GPOINTER_TO_INT (gee_map_entry_get_value (e1));
	return result;
}


static gint __lambda1__gcompare_data_func (void* a, void* b, gpointer self) {
	gint result;
	result = _lambda1_ (a, b);
	return result;
}


GeeList* synapse_query_get_matchers_for_query (const char* query, SynapseMatcherFlags match_flags, GRegexCompileFlags flags) {
	GeeList* result = NULL;
	GeeHashMap* results;
	GRegex* re;
	gint individual_words_length1;
	gint _individual_words_size_;
	char** _tmp18_;
	char* _tmp15_;
	char** _tmp16_;
	char** _tmp17_;
	char** individual_words;
	gint individual_chars_length1;
	gint _individual_chars_size_;
	char** _tmp42_;
	char** _tmp41_;
	char** individual_chars;
	gint escaped_chars_length1;
	gint _escaped_chars_size_;
	char** _tmp44_;
	char** _tmp43_ = NULL;
	char** escaped_chars;
	gboolean _tmp45_ = FALSE;
	gboolean _tmp46_ = FALSE;
	gboolean _tmp51_ = FALSE;
	GeeArrayList* sorted_results;
	GeeSet* entries;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (query != NULL, NULL);
	results = gee_hash_map_new (G_TYPE_REGEX, (GBoxedCopyFunc) g_regex_ref, g_regex_unref, G_TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	re = NULL;
	{
		char* _tmp0_;
		char* _tmp1_;
		GRegex* _tmp2_;
		GRegex* _tmp3_;
		GRegex* _tmp4_;
		_tmp3_ = (_tmp2_ = g_regex_new (_tmp1_ = g_strdup_printf ("^(%s)$", _tmp0_ = g_regex_escape_string (query, -1)), flags, 0, &_inner_error_), _g_free0 (_tmp1_), _g_free0 (_tmp0_), _tmp2_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch14_g_regex_error;
			}
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		re = (_tmp4_ = _tmp3_, _g_regex_unref0 (re), _tmp4_);
		gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_HIGHEST));
	}
	goto __finally14;
	__catch14_g_regex_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally14:
	if (_inner_error_ != NULL) {
		_g_regex_unref0 (re);
		_g_object_unref0 (results);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	{
		char* _tmp5_;
		char* _tmp6_;
		GRegex* _tmp7_;
		GRegex* _tmp8_;
		GRegex* _tmp9_;
		_tmp8_ = (_tmp7_ = g_regex_new (_tmp6_ = g_strdup_printf ("^(%s)", _tmp5_ = g_regex_escape_string (query, -1)), flags, 0, &_inner_error_), _g_free0 (_tmp6_), _g_free0 (_tmp5_), _tmp7_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch15_g_regex_error;
			}
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		re = (_tmp9_ = _tmp8_, _g_regex_unref0 (re), _tmp9_);
		gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_EXCELLENT));
	}
	goto __finally15;
	__catch15_g_regex_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally15:
	if (_inner_error_ != NULL) {
		_g_regex_unref0 (re);
		_g_object_unref0 (results);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	{
		char* _tmp10_;
		char* _tmp11_;
		GRegex* _tmp12_;
		GRegex* _tmp13_;
		GRegex* _tmp14_;
		_tmp13_ = (_tmp12_ = g_regex_new (_tmp11_ = g_strdup_printf ("\\b(%s)", _tmp10_ = g_regex_escape_string (query, -1)), flags, 0, &_inner_error_), _g_free0 (_tmp11_), _g_free0 (_tmp10_), _tmp12_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch16_g_regex_error;
			}
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		re = (_tmp14_ = _tmp13_, _g_regex_unref0 (re), _tmp14_);
		gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_VERY_GOOD));
	}
	goto __finally16;
	__catch16_g_regex_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			_g_error_free0 (err);
		}
	}
	__finally16:
	if (_inner_error_ != NULL) {
		_g_regex_unref0 (re);
		_g_object_unref0 (results);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	individual_words = (_tmp18_ = (_tmp17_ = _tmp16_ = g_regex_split_simple ("\\s+", _tmp15_ = string_strip (query), 0, 0), _g_free0 (_tmp15_), _tmp17_), individual_words_length1 = _vala_array_length (_tmp16_), _individual_words_size_ = individual_words_length1, _tmp18_);
	if (individual_words_length1 >= 2) {
		gint escaped_words_length1;
		gint _escaped_words_size_;
		char** _tmp20_;
		char** _tmp19_ = NULL;
		char** escaped_words;
		char* _tmp21_;
		char* _tmp22_;
		char* pattern;
		escaped_words = (_tmp20_ = (_tmp19_ = g_new0 (char*, 0 + 1), _tmp19_), escaped_words_length1 = 0, _escaped_words_size_ = escaped_words_length1, _tmp20_);
		{
			char** word_collection;
			int word_collection_length1;
			int word_it;
			word_collection = individual_words;
			word_collection_length1 = individual_words_length1;
			for (word_it = 0; word_it < individual_words_length1; word_it = word_it + 1) {
				const char* word;
				word = word_collection[word_it];
				{
					_vala_array_add6 (&escaped_words, &escaped_words_length1, &_escaped_words_size_, g_regex_escape_string (word, -1));
				}
			}
		}
		pattern = (_tmp22_ = g_strdup_printf ("\\b(%s)", _tmp21_ = g_strjoinv (").+\\b(", escaped_words)), _g_free0 (_tmp21_), _tmp22_);
		{
			GRegex* _tmp23_;
			GRegex* _tmp24_;
			_tmp23_ = g_regex_new (pattern, flags, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch17_g_regex_error;
				}
				_g_free0 (pattern);
				escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
				individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
				_g_regex_unref0 (re);
				_g_object_unref0 (results);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			re = (_tmp24_ = _tmp23_, _g_regex_unref0 (re), _tmp24_);
			gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_GOOD));
		}
		goto __finally17;
		__catch17_g_regex_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (err);
			}
		}
		__finally17:
		if (_inner_error_ != NULL) {
			_g_free0 (pattern);
			escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
			individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		if (!((match_flags & SYNAPSE_MATCHER_FLAGS_NO_REVERSED) == SYNAPSE_MATCHER_FLAGS_NO_REVERSED)) {
			if (escaped_words_length1 == 2) {
				char* _tmp25_;
				char* _tmp26_;
				char* reversed;
				reversed = (_tmp26_ = g_strdup_printf ("\\b(%s)", _tmp25_ = g_strjoin (").+\\b(", escaped_words[1], escaped_words[0], NULL, NULL)), _g_free0 (_tmp25_), _tmp26_);
				{
					GRegex* _tmp27_;
					GRegex* _tmp28_;
					_tmp27_ = g_regex_new (reversed, flags, 0, &_inner_error_);
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == G_REGEX_ERROR) {
							goto __catch18_g_regex_error;
						}
						_g_free0 (reversed);
						_g_free0 (pattern);
						escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
						individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
						_g_regex_unref0 (re);
						_g_object_unref0 (results);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
					re = (_tmp28_ = _tmp27_, _g_regex_unref0 (re), _tmp28_);
					gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) (SYNAPSE_MATCH_SCORE_GOOD - SYNAPSE_MATCH_SCORE_INCREMENT_MINOR)));
				}
				goto __finally18;
				__catch18_g_regex_error:
				{
					GError * err;
					err = _inner_error_;
					_inner_error_ = NULL;
					{
						_g_error_free0 (err);
					}
				}
				__finally18:
				if (_inner_error_ != NULL) {
					_g_free0 (reversed);
					_g_free0 (pattern);
					escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
					individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
					_g_regex_unref0 (re);
					_g_object_unref0 (results);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
				_g_free0 (reversed);
			} else {
				char* _tmp29_;
				char* _tmp30_;
				char* orred;
				char* any_order;
				orred = (_tmp30_ = g_strdup_printf ("\\b((?:%s))", _tmp29_ = g_strjoinv (")|(?:", escaped_words)), _g_free0 (_tmp29_), _tmp30_);
				any_order = g_strdup ("");
				{
					gint i;
					i = 0;
					{
						gboolean _tmp31_;
						_tmp31_ = TRUE;
						while (TRUE) {
							gboolean is_last;
							char* _tmp32_;
							if (!_tmp31_) {
								i++;
							}
							_tmp31_ = FALSE;
							if (!(i < escaped_words_length1)) {
								break;
							}
							is_last = i == (escaped_words_length1 - 1);
							any_order = (_tmp32_ = g_strconcat (any_order, orred, NULL), _g_free0 (any_order), _tmp32_);
							if (!is_last) {
								char* _tmp33_;
								any_order = (_tmp33_ = g_strconcat (any_order, ".+", NULL), _g_free0 (any_order), _tmp33_);
							}
						}
					}
				}
				{
					GRegex* _tmp34_;
					GRegex* _tmp35_;
					_tmp34_ = g_regex_new (any_order, flags, 0, &_inner_error_);
					if (_inner_error_ != NULL) {
						if (_inner_error_->domain == G_REGEX_ERROR) {
							goto __catch19_g_regex_error;
						}
						_g_free0 (any_order);
						_g_free0 (orred);
						_g_free0 (pattern);
						escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
						individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
						_g_regex_unref0 (re);
						_g_object_unref0 (results);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return NULL;
					}
					re = (_tmp35_ = _tmp34_, _g_regex_unref0 (re), _tmp35_);
					gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) (SYNAPSE_MATCH_SCORE_ABOVE_AVERAGE + SYNAPSE_MATCH_SCORE_INCREMENT_MINOR)));
				}
				goto __finally19;
				__catch19_g_regex_error:
				{
					GError * err;
					err = _inner_error_;
					_inner_error_ = NULL;
					{
						_g_error_free0 (err);
					}
				}
				__finally19:
				if (_inner_error_ != NULL) {
					_g_free0 (any_order);
					_g_free0 (orred);
					_g_free0 (pattern);
					escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
					individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
					_g_regex_unref0 (re);
					_g_object_unref0 (results);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
				_g_free0 (any_order);
				_g_free0 (orred);
			}
		}
		_g_free0 (pattern);
		escaped_words = (_vala_array_free (escaped_words, escaped_words_length1, (GDestroyNotify) g_free), NULL);
	}
	if (!((match_flags & SYNAPSE_MATCHER_FLAGS_NO_SUBSTRING) == SYNAPSE_MATCHER_FLAGS_NO_SUBSTRING)) {
		{
			char* _tmp36_;
			char* _tmp37_;
			GRegex* _tmp38_;
			GRegex* _tmp39_;
			GRegex* _tmp40_;
			_tmp39_ = (_tmp38_ = g_regex_new (_tmp37_ = g_strdup_printf ("(%s)", _tmp36_ = g_regex_escape_string (query, -1)), flags, 0, &_inner_error_), _g_free0 (_tmp37_), _g_free0 (_tmp36_), _tmp38_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch20_g_regex_error;
				}
				individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
				_g_regex_unref0 (re);
				_g_object_unref0 (results);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			re = (_tmp40_ = _tmp39_, _g_regex_unref0 (re), _tmp40_);
			gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_AVERAGE));
		}
		goto __finally20;
		__catch20_g_regex_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (err);
			}
		}
		__finally20:
		if (_inner_error_ != NULL) {
			individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	individual_chars = (_tmp42_ = _tmp41_ = g_regex_split_simple ("\\s*", query, 0, 0), individual_chars_length1 = _vala_array_length (_tmp41_), _individual_chars_size_ = individual_chars_length1, _tmp42_);
	escaped_chars = (_tmp44_ = (_tmp43_ = g_new0 (char*, 0 + 1), _tmp43_), escaped_chars_length1 = 0, _escaped_chars_size_ = escaped_chars_length1, _tmp44_);
	{
		char** word_collection;
		int word_collection_length1;
		int word_it;
		word_collection = individual_chars;
		word_collection_length1 = individual_chars_length1;
		for (word_it = 0; word_it < individual_chars_length1; word_it = word_it + 1) {
			const char* word;
			word = word_collection[word_it];
			{
				_vala_array_add7 (&escaped_chars, &escaped_chars_length1, &_escaped_chars_size_, g_regex_escape_string (word, -1));
			}
		}
	}
	if (!((match_flags & SYNAPSE_MATCHER_FLAGS_NO_PARTIAL) == SYNAPSE_MATCHER_FLAGS_NO_PARTIAL)) {
		_tmp46_ = individual_words_length1 == 1;
	} else {
		_tmp46_ = FALSE;
	}
	if (_tmp46_) {
		_tmp45_ = individual_chars_length1 <= 5;
	} else {
		_tmp45_ = FALSE;
	}
	if (_tmp45_) {
		char* _tmp47_;
		char* _tmp48_;
		char* pattern;
		pattern = (_tmp48_ = g_strdup_printf ("\\b(%s)", _tmp47_ = g_strjoinv (").+\\b(", escaped_chars)), _g_free0 (_tmp47_), _tmp48_);
		{
			GRegex* _tmp49_;
			GRegex* _tmp50_;
			_tmp49_ = g_regex_new (pattern, flags, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch21_g_regex_error;
				}
				_g_free0 (pattern);
				escaped_chars = (_vala_array_free (escaped_chars, escaped_chars_length1, (GDestroyNotify) g_free), NULL);
				individual_chars = (_vala_array_free (individual_chars, individual_chars_length1, (GDestroyNotify) g_free), NULL);
				individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
				_g_regex_unref0 (re);
				_g_object_unref0 (results);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			re = (_tmp50_ = _tmp49_, _g_regex_unref0 (re), _tmp50_);
			gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_ABOVE_AVERAGE));
		}
		goto __finally21;
		__catch21_g_regex_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (err);
			}
		}
		__finally21:
		if (_inner_error_ != NULL) {
			_g_free0 (pattern);
			escaped_chars = (_vala_array_free (escaped_chars, escaped_chars_length1, (GDestroyNotify) g_free), NULL);
			individual_chars = (_vala_array_free (individual_chars, individual_chars_length1, (GDestroyNotify) g_free), NULL);
			individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_free0 (pattern);
	}
	if (!((match_flags & SYNAPSE_MATCHER_FLAGS_NO_FUZZY) == SYNAPSE_MATCHER_FLAGS_NO_FUZZY)) {
		_tmp51_ = escaped_chars_length1 > 0;
	} else {
		_tmp51_ = FALSE;
	}
	if (_tmp51_) {
		char* _tmp52_;
		char* _tmp53_;
		char* pattern;
		pattern = (_tmp53_ = g_strdup_printf ("\\b(%s)", _tmp52_ = g_strjoinv (").*(", escaped_chars)), _g_free0 (_tmp52_), _tmp53_);
		{
			GRegex* _tmp54_;
			GRegex* _tmp55_;
			_tmp54_ = g_regex_new (pattern, flags, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch22_g_regex_error;
				}
				_g_free0 (pattern);
				escaped_chars = (_vala_array_free (escaped_chars, escaped_chars_length1, (GDestroyNotify) g_free), NULL);
				individual_chars = (_vala_array_free (individual_chars, individual_chars_length1, (GDestroyNotify) g_free), NULL);
				individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
				_g_regex_unref0 (re);
				_g_object_unref0 (results);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			re = (_tmp55_ = _tmp54_, _g_regex_unref0 (re), _tmp55_);
			gee_abstract_map_set ((GeeAbstractMap*) results, re, GINT_TO_POINTER ((gint) SYNAPSE_MATCH_SCORE_POOR));
		}
		goto __finally22;
		__catch22_g_regex_error:
		{
			GError * err;
			err = _inner_error_;
			_inner_error_ = NULL;
			{
				_g_error_free0 (err);
			}
		}
		__finally22:
		if (_inner_error_ != NULL) {
			_g_free0 (pattern);
			escaped_chars = (_vala_array_free (escaped_chars, escaped_chars_length1, (GDestroyNotify) g_free), NULL);
			individual_chars = (_vala_array_free (individual_chars, individual_chars_length1, (GDestroyNotify) g_free), NULL);
			individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
			_g_regex_unref0 (re);
			_g_object_unref0 (results);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_free0 (pattern);
	}
	sorted_results = gee_array_list_new (GEE_MAP_TYPE_ENTRY, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL, NULL, NULL);
	entries = gee_map_get_entries ((GeeMap*) results);
	g_object_set_data_full ((GObject*) sorted_results, "entries-ref", _g_object_ref0 (entries), g_object_unref);
	gee_abstract_collection_add_all ((GeeAbstractCollection*) sorted_results, (GeeCollection*) entries);
	gee_list_sort ((GeeList*) sorted_results, __lambda1__gcompare_data_func, NULL, NULL);
	result = (GeeList*) sorted_results;
	_g_object_unref0 (entries);
	escaped_chars = (_vala_array_free (escaped_chars, escaped_chars_length1, (GDestroyNotify) g_free), NULL);
	individual_chars = (_vala_array_free (individual_chars, individual_chars_length1, (GDestroyNotify) g_free), NULL);
	individual_words = (_vala_array_free (individual_words, individual_words_length1, (GDestroyNotify) g_free), NULL);
	_g_regex_unref0 (re);
	_g_object_unref0 (results);
	return result;
}


void synapse_query_copy (const SynapseQuery* self, SynapseQuery* dest) {
	dest->query_string = g_strdup (self->query_string);
	dest->query_string_folded = g_strdup (self->query_string_folded);
	dest->cancellable = _g_object_ref0 (self->cancellable);
	dest->query_type = self->query_type;
	dest->max_results = self->max_results;
	dest->query_id = self->query_id;
}


void synapse_query_destroy (SynapseQuery* self) {
	_g_free0 (self->query_string);
	_g_free0 (self->query_string_folded);
	_g_object_unref0 (self->cancellable);
}


SynapseQuery* synapse_query_dup (const SynapseQuery* self) {
	SynapseQuery* dup;
	dup = g_new0 (SynapseQuery, 1);
	synapse_query_copy (self, dup);
	return dup;
}


void synapse_query_free (SynapseQuery* self) {
	synapse_query_destroy (self);
	g_free (self);
}


GType synapse_query_get_type (void) {
	static volatile gsize synapse_query_type_id__volatile = 0;
	if (g_once_init_enter (&synapse_query_type_id__volatile)) {
		GType synapse_query_type_id;
		synapse_query_type_id = g_boxed_type_register_static ("SynapseQuery", (GBoxedCopyFunc) synapse_query_dup, (GBoxedFreeFunc) synapse_query_free);
		g_once_init_leave (&synapse_query_type_id__volatile, synapse_query_type_id);
	}
	return synapse_query_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




