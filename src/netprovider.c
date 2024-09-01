/* netprovider.c generated by valac 0.14.2, the Vala compiler
 * generated from netprovider.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glibtop/netlist.h>
#include <glibtop/netload.h>
#include <glib/gstdio.h>
#include <float.h>
#include <math.h>


#define TYPE_PROVIDER (provider_get_type ())
#define PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROVIDER, Provider))
#define PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROVIDER, ProviderClass))
#define IS_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROVIDER))
#define IS_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROVIDER))
#define PROVIDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROVIDER, ProviderClass))

typedef struct _Provider Provider;
typedef struct _ProviderClass ProviderClass;
typedef struct _ProviderPrivate ProviderPrivate;

#define TYPE_NET_PROVIDER (net_provider_get_type ())
#define NET_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_NET_PROVIDER, NetProvider))
#define NET_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_NET_PROVIDER, NetProviderClass))
#define IS_NET_PROVIDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_NET_PROVIDER))
#define IS_NET_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_NET_PROVIDER))
#define NET_PROVIDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_NET_PROVIDER, NetProviderClass))

typedef struct _NetProvider NetProvider;
typedef struct _NetProviderClass NetProviderClass;
typedef struct _NetProviderPrivate NetProviderPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _Provider {
	GObject parent_instance;
	ProviderPrivate * priv;
};

struct _ProviderClass {
	GObjectClass parent_class;
	void (*update) (Provider* self);
};

struct _NetProvider {
	Provider parent_instance;
	NetProviderPrivate * priv;
};

struct _NetProviderClass {
	ProviderClass parent_class;
};

struct _NetProviderPrivate {
	guint64* lastdata;
	gint lastdata_length1;
	gint _lastdata_size_;
	guint64 lasttime;
};


static gpointer net_provider_parent_class = NULL;

GType provider_get_type (void) G_GNUC_CONST;
GType net_provider_get_type (void) G_GNUC_CONST;
#define NET_PROVIDER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_NET_PROVIDER, NetProviderPrivate))
enum  {
	NET_PROVIDER_DUMMY_PROPERTY
};
NetProvider* net_provider_new (void);
NetProvider* net_provider_construct (GType object_type);
Provider* provider_construct (GType object_type, const gchar* id, gchar** keys, int keys_length1);
static void net_provider_real_update (Provider* base);
gdouble* provider_get_values (Provider* self, int* result_length1);
static guint64* _vala_array_dup18 (guint64* self, int length);
static void net_provider_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


NetProvider* net_provider_construct (GType object_type) {
	NetProvider * self = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar** _tmp3_ = NULL;
	gchar** _tmp4_;
	gint _tmp4__length1;
	_tmp0_ = g_strdup ("down");
	_tmp1_ = g_strdup ("up");
	_tmp2_ = g_strdup ("local");
	_tmp3_ = g_new0 (gchar*, 3 + 1);
	_tmp3_[0] = _tmp0_;
	_tmp3_[1] = _tmp1_;
	_tmp3_[2] = _tmp2_;
	_tmp4_ = _tmp3_;
	_tmp4__length1 = 3;
	self = (NetProvider*) provider_construct (object_type, "net", _tmp4_, 3);
	_tmp4_ = (_vala_array_free (_tmp4_, _tmp4__length1, (GDestroyNotify) g_free), NULL);
	return self;
}


NetProvider* net_provider_new (void) {
	return net_provider_construct (TYPE_NET_PROVIDER);
}


static guint64* _vala_array_dup18 (guint64* self, int length) {
	return g_memdup (self, length * sizeof (guint64));
}


static void net_provider_real_update (Provider* base) {
	NetProvider * self;
	guint64* _tmp0_ = NULL;
	guint64* newdata;
	gint newdata_length1;
	gint _newdata_size_;
	guint64 _tmp1_ = 0ULL;
	guint64 newtime;
	gchar** devices = NULL;
	gint devices_length1 = 0;
	gint _devices_size_ = 0;
	glibtop_netlist netlist = {0};
	glibtop_netlist _tmp2_ = {0};
	gchar** _tmp3_;
	gchar** _tmp4_ = NULL;
	glibtop_netlist _tmp5_;
	guint32 _tmp6_;
	guint64* _tmp89_;
	gint _tmp89__length1;
	guint64* _tmp110_;
	gint _tmp110__length1;
	guint64* _tmp111_;
	gint _tmp111__length1;
	guint64 _tmp112_;
	self = NET_PROVIDER (base);
	_tmp0_ = g_new0 (guint64, 3);
	newdata = _tmp0_;
	newdata_length1 = 3;
	_newdata_size_ = newdata_length1;
	_tmp1_ = g_get_monotonic_time ();
	newtime = _tmp1_;
	_tmp4_ = _tmp3_ = glibtop_get_netlist (&_tmp2_);
	netlist = _tmp2_;
	devices = (_vala_array_free (devices, devices_length1, (GDestroyNotify) g_free), NULL);
	devices = _tmp4_;
	devices_length1 = _vala_array_length (_tmp3_);
	_devices_size_ = devices_length1;
	_tmp5_ = netlist;
	_tmp6_ = _tmp5_.number;
	g_debug ("netprovider.vala:34: Netlist: %u entries", (guint) _tmp6_);
	{
		guint i;
		i = (guint) 0;
		{
			gboolean _tmp7_;
			_tmp7_ = TRUE;
			while (TRUE) {
				gboolean _tmp8_;
				guint _tmp10_;
				glibtop_netlist _tmp11_;
				guint32 _tmp12_;
				glibtop_netload netload = {0};
				gchar** _tmp13_;
				gint _tmp13__length1;
				guint _tmp14_;
				const gchar* _tmp15_;
				glibtop_netload _tmp16_ = {0};
				gchar** _tmp17_;
				gint _tmp17__length1;
				guint _tmp18_;
				const gchar* _tmp19_;
				glibtop_netload _tmp20_;
				guint64 _tmp21_;
				glibtop_netload _tmp22_;
				guint64 _tmp23_;
				glibtop_netload _tmp24_;
				guint32 _tmp25_;
				glibtop_netload _tmp26_;
				guint32 _tmp27_;
				glibtop_netload _tmp28_;
				guint32 _tmp29_;
				glibtop_netload _tmp30_;
				guint64 _tmp31_;
				glibtop_netload _tmp32_;
				guint64 _tmp33_;
				glibtop_netload _tmp34_;
				guint64 _tmp35_;
				glibtop_netload _tmp36_;
				guint64 _tmp37_;
				glibtop_netload _tmp38_;
				guint64 _tmp39_;
				glibtop_netload _tmp40_;
				guint64 _tmp41_;
				glibtop_netload _tmp42_;
				guint64 _tmp43_;
				glibtop_netload _tmp44_;
				guint64 _tmp45_;
				glibtop_netload _tmp46_;
				guint64 _tmp47_;
				glibtop_netload _tmp48_;
				guint64 _tmp49_;
				glibtop_netload _tmp50_;
				guint64 _tmp51_;
				gint _tmp52_;
				glibtop_netload _tmp53_;
				guint64 _tmp54_;
				gint _tmp55_;
				_tmp8_ = _tmp7_;
				if (!_tmp8_) {
					guint _tmp9_;
					_tmp9_ = i;
					i = _tmp9_ + 1;
				}
				_tmp7_ = FALSE;
				_tmp10_ = i;
				_tmp11_ = netlist;
				_tmp12_ = _tmp11_.number;
				if (!(_tmp10_ < ((guint) _tmp12_))) {
					break;
				}
				_tmp13_ = devices;
				_tmp13__length1 = devices_length1;
				_tmp14_ = i;
				_tmp15_ = _tmp13_[_tmp14_];
				glibtop_get_netload (&_tmp16_, _tmp15_);
				netload = _tmp16_;
				_tmp17_ = devices;
				_tmp17__length1 = devices_length1;
				_tmp18_ = i;
				_tmp19_ = _tmp17_[_tmp18_];
				g_debug ("netprovider.vala:38: Netload: %s", _tmp19_);
				_tmp20_ = netload;
				_tmp21_ = _tmp20_.flags;
				g_debug ("netprovider.vala:39:   flags: %llx", _tmp21_);
				_tmp22_ = netload;
				_tmp23_ = _tmp22_.if_flags;
				g_debug ("netprovider.vala:40:   if flags: %llx", _tmp23_);
				_tmp24_ = netload;
				_tmp25_ = _tmp24_.mtu;
				g_debug ("netprovider.vala:41:   mtu: %u", (guint) _tmp25_);
				_tmp26_ = netload;
				_tmp27_ = _tmp26_.subnet;
				g_debug ("netprovider.vala:42:   subnet: %u", (guint) _tmp27_);
				_tmp28_ = netload;
				_tmp29_ = _tmp28_.address;
				g_debug ("netprovider.vala:43:   address: %u", (guint) _tmp29_);
				_tmp30_ = netload;
				_tmp31_ = _tmp30_.packets_in;
				g_debug ("netprovider.vala:44:   packets in: %llu", _tmp31_);
				_tmp32_ = netload;
				_tmp33_ = _tmp32_.packets_out;
				g_debug ("netprovider.vala:45:   packets out: %llu", _tmp33_);
				_tmp34_ = netload;
				_tmp35_ = _tmp34_.packets_total;
				g_debug ("netprovider.vala:46:   packets total: %llu", _tmp35_);
				_tmp36_ = netload;
				_tmp37_ = _tmp36_.bytes_in;
				g_debug ("netprovider.vala:47:   bytes in: %llu", _tmp37_);
				_tmp38_ = netload;
				_tmp39_ = _tmp38_.bytes_out;
				g_debug ("netprovider.vala:48:   bytes out: %llu", _tmp39_);
				_tmp40_ = netload;
				_tmp41_ = _tmp40_.bytes_total;
				g_debug ("netprovider.vala:49:   bytes total: %llu", _tmp41_);
				_tmp42_ = netload;
				_tmp43_ = _tmp42_.errors_in;
				g_debug ("netprovider.vala:50:   errors in: %llu", _tmp43_);
				_tmp44_ = netload;
				_tmp45_ = _tmp44_.errors_out;
				g_debug ("netprovider.vala:51:   errors out: %llu", _tmp45_);
				_tmp46_ = netload;
				_tmp47_ = _tmp46_.errors_total;
				g_debug ("netprovider.vala:52:   errors total: %llu", _tmp47_);
				_tmp48_ = netload;
				_tmp49_ = _tmp48_.collisions;
				g_debug ("netprovider.vala:53:   collisions: %llu", _tmp49_);
				_tmp50_ = netload;
				_tmp51_ = _tmp50_.if_flags;
				_tmp52_ = GLIBTOP_IF_FLAGS_UP;
				_tmp53_ = netload;
				_tmp54_ = _tmp53_.if_flags;
				_tmp55_ = GLIBTOP_IF_FLAGS_RUNNING;
				if (((_tmp51_ & (1L << _tmp52_)) == ((guint64) 0)) | ((_tmp54_ & (1L << _tmp55_)) == ((guint64) 0))) {
					g_debug ("netprovider.vala:57:   down or not running");
				} else {
					gchar** _tmp56_;
					gint _tmp56__length1;
					guint _tmp57_;
					const gchar* _tmp58_;
					gchar* _tmp59_ = NULL;
					gchar* _tmp60_;
					gboolean _tmp61_ = FALSE;
					gboolean _tmp62_;
					_tmp56_ = devices;
					_tmp56__length1 = devices_length1;
					_tmp57_ = i;
					_tmp58_ = _tmp56_[_tmp57_];
					_tmp59_ = g_strdup_printf ("/sys/class/net/%s/device", _tmp58_);
					_tmp60_ = _tmp59_;
					_tmp61_ = g_file_test (_tmp60_, G_FILE_TEST_EXISTS);
					_tmp62_ = _tmp61_;
					_g_free0 (_tmp60_);
					if (_tmp62_) {
						guint64* _tmp63_;
						gint _tmp63__length1;
						glibtop_netload _tmp64_;
						guint64 _tmp65_;
						guint64 _tmp66_;
						guint64* _tmp67_;
						gint _tmp67__length1;
						glibtop_netload _tmp68_;
						guint64 _tmp69_;
						guint64 _tmp70_;
						_tmp63_ = newdata;
						_tmp63__length1 = newdata_length1;
						_tmp64_ = netload;
						_tmp65_ = _tmp64_.bytes_in;
						_tmp63_[0] += _tmp65_;
						_tmp66_ = _tmp63_[0];
						_tmp67_ = newdata;
						_tmp67__length1 = newdata_length1;
						_tmp68_ = netload;
						_tmp69_ = _tmp68_.bytes_out;
						_tmp67_[1] += _tmp69_;
						_tmp70_ = _tmp67_[1];
						g_debug ("netprovider.vala:61:   existing device link");
					} else {
						glibtop_netload _tmp71_;
						guint64 _tmp72_;
						gint _tmp73_;
						_tmp71_ = netload;
						_tmp72_ = _tmp71_.if_flags;
						_tmp73_ = GLIBTOP_IF_FLAGS_POINTOPOINT;
						if ((_tmp72_ & (1L << _tmp73_)) > ((guint64) 0)) {
							guint64* _tmp74_;
							gint _tmp74__length1;
							glibtop_netload _tmp75_;
							guint64 _tmp76_;
							guint64 _tmp77_;
							guint64* _tmp78_;
							gint _tmp78__length1;
							glibtop_netload _tmp79_;
							guint64 _tmp80_;
							guint64 _tmp81_;
							_tmp74_ = newdata;
							_tmp74__length1 = newdata_length1;
							_tmp75_ = netload;
							_tmp76_ = _tmp75_.bytes_in;
							_tmp74_[0] += _tmp76_;
							_tmp77_ = _tmp74_[0];
							_tmp78_ = newdata;
							_tmp78__length1 = newdata_length1;
							_tmp79_ = netload;
							_tmp80_ = _tmp79_.bytes_out;
							_tmp78_[1] += _tmp80_;
							_tmp81_ = _tmp78_[1];
							g_debug ("netprovider.vala:65:   pointtopoint");
						} else {
							glibtop_netload _tmp82_;
							guint64 _tmp83_;
							gint _tmp84_;
							_tmp82_ = netload;
							_tmp83_ = _tmp82_.if_flags;
							_tmp84_ = GLIBTOP_IF_FLAGS_LOOPBACK;
							if ((_tmp83_ & (1L << _tmp84_)) > ((guint64) 0)) {
								guint64* _tmp85_;
								gint _tmp85__length1;
								glibtop_netload _tmp86_;
								guint64 _tmp87_;
								guint64 _tmp88_;
								_tmp85_ = newdata;
								_tmp85__length1 = newdata_length1;
								_tmp86_ = netload;
								_tmp87_ = _tmp86_.bytes_in;
								_tmp85_[2] += _tmp87_;
								_tmp88_ = _tmp85_[2];
								g_debug ("netprovider.vala:68:   loopback");
							} else {
								g_debug ("netprovider.vala:70:   unknown");
							}
						}
					}
				}
			}
		}
	}
	_tmp89_ = self->priv->lastdata;
	_tmp89__length1 = self->priv->lastdata_length1;
	if (_tmp89__length1 != 0) {
		guint64 _tmp90_;
		guint64 _tmp91_;
		gdouble delta;
		_tmp90_ = newtime;
		_tmp91_ = self->priv->lasttime;
		delta = (_tmp90_ - _tmp91_) / 1e6;
		{
			guint i;
			gdouble* _tmp92_;
			gint _tmp92__length1;
			gdouble* _tmp93_;
			gint _tmp93__length1;
			guint isize;
			i = (guint) 0;
			_tmp92_ = provider_get_values (PROVIDER (self), &_tmp92__length1);
			_tmp93_ = _tmp92_;
			_tmp93__length1 = _tmp92__length1;
			isize = (guint) _tmp93__length1;
			{
				gboolean _tmp94_;
				_tmp94_ = TRUE;
				while (TRUE) {
					gboolean _tmp95_;
					guint _tmp97_;
					guint _tmp98_;
					gdouble* _tmp99_;
					gint _tmp99__length1;
					gdouble* _tmp100_;
					gint _tmp100__length1;
					guint _tmp101_;
					guint64* _tmp102_;
					gint _tmp102__length1;
					guint _tmp103_;
					guint64 _tmp104_;
					guint64* _tmp105_;
					gint _tmp105__length1;
					guint _tmp106_;
					guint64 _tmp107_;
					gdouble _tmp108_;
					gdouble _tmp109_;
					_tmp95_ = _tmp94_;
					if (!_tmp95_) {
						guint _tmp96_;
						_tmp96_ = i;
						i = _tmp96_ + 1;
					}
					_tmp94_ = FALSE;
					_tmp97_ = i;
					_tmp98_ = isize;
					if (!(_tmp97_ < _tmp98_)) {
						break;
					}
					_tmp99_ = provider_get_values (PROVIDER (self), &_tmp99__length1);
					_tmp100_ = _tmp99_;
					_tmp100__length1 = _tmp99__length1;
					_tmp101_ = i;
					_tmp102_ = newdata;
					_tmp102__length1 = newdata_length1;
					_tmp103_ = i;
					_tmp104_ = _tmp102_[_tmp103_];
					_tmp105_ = self->priv->lastdata;
					_tmp105__length1 = self->priv->lastdata_length1;
					_tmp106_ = i;
					_tmp107_ = _tmp105_[_tmp106_];
					_tmp108_ = delta;
					_tmp100_[_tmp101_] = (_tmp104_ - _tmp107_) / _tmp108_;
					_tmp109_ = _tmp100_[_tmp101_];
				}
			}
		}
	}
	_tmp110_ = newdata;
	_tmp110__length1 = newdata_length1;
	_tmp111_ = (_tmp110_ != NULL) ? _vala_array_dup18 (_tmp110_, _tmp110__length1) : ((gpointer) _tmp110_);
	_tmp111__length1 = _tmp110__length1;
	self->priv->lastdata = (g_free (self->priv->lastdata), NULL);
	self->priv->lastdata = _tmp111_;
	self->priv->lastdata_length1 = _tmp111__length1;
	self->priv->_lastdata_size_ = self->priv->lastdata_length1;
	_tmp112_ = newtime;
	self->priv->lasttime = _tmp112_;
	devices = (_vala_array_free (devices, devices_length1, (GDestroyNotify) g_free), NULL);
	newdata = (g_free (newdata), NULL);
}


static void net_provider_class_init (NetProviderClass * klass) {
	net_provider_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (NetProviderPrivate));
	PROVIDER_CLASS (klass)->update = net_provider_real_update;
	G_OBJECT_CLASS (klass)->finalize = net_provider_finalize;
}


static void net_provider_instance_init (NetProvider * self) {
	self->priv = NET_PROVIDER_GET_PRIVATE (self);
}


static void net_provider_finalize (GObject* obj) {
	NetProvider * self;
	self = NET_PROVIDER (obj);
	self->priv->lastdata = (g_free (self->priv->lastdata), NULL);
	G_OBJECT_CLASS (net_provider_parent_class)->finalize (obj);
}


/******************************************************************************
 * Copyright (C) 2011  Michael Hofmann <mh21@piware.de>                       *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program; if not, write to the Free Software Foundation, Inc.,    *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                *
 ******************************************************************************/
GType net_provider_get_type (void) {
	static volatile gsize net_provider_type_id__volatile = 0;
	if (g_once_init_enter (&net_provider_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (NetProviderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) net_provider_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NetProvider), 0, (GInstanceInitFunc) net_provider_instance_init, NULL };
		GType net_provider_type_id;
		net_provider_type_id = g_type_register_static (TYPE_PROVIDER, "NetProvider", &g_define_type_info, 0);
		g_once_init_leave (&net_provider_type_id__volatile, net_provider_type_id);
	}
	return net_provider_type_id__volatile;
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



