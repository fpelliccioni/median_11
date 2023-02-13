
#define Regular typename
#define StrictWeakOrdering typename
#define requires(...)

#include  <utility>

namespace tao::algorithm {

template <bool strict, StrictWeakOrdering R>
struct compare_strict_or_reflexive;

template <StrictWeakOrdering R>
struct compare_strict_or_reflexive<true, R> { // strict
    template <Regular A, Regular B>
        requires(Same<A, B> && Domain<R, A>)
    inline constexpr
    bool operator()(A&& a, B&& b, R r) const {
        return r(std::forward<A>(a), std::forward<B>(b));
    }
};

template <StrictWeakOrdering R>
struct compare_strict_or_reflexive<false, R> { // reflexive
    template <Regular A, Regular B>
        requires(Same<A, B> && Domain<R, A>)
    inline constexpr
    bool operator()(A&& a, B&& b, R r) const {
        return !r(std::forward<B>(b), std::forward<A>(a)); // complement_of_converse(r(a, b))
    }
};


// find_22 *******************
template <int ai, int bi, Regular A, Regular B, StrictWeakOrdering R>
    requires(Same<A, B> && Domain<R, A>)
inline constexpr
auto&& select_0_2(A&& a, B&& b, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return std::forward<A>(a);
    return std::forward<B>(b);
}

// find_33 *******************
template <int ai, int bi, Regular A, Regular B, StrictWeakOrdering R>
    requires(Same<A, B> && Domain<R, A>)
inline constexpr
auto&& select_1_2(A&& a, B&& b, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return std::forward<B>(b);
    return std::forward<A>(a);
}

// find_21 *******************
template <int ai, int bi, int ci, Regular A, Regular B, Regular C, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Domain<R, A>)
inline constexpr
auto&& select_1_3_cb(A&& a, B&& b, C&& c, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return std::forward<B>(b);
    return select_0_2<ai, ci>(std::forward<A>(a), std::forward<C>(c), r);
}

// find_36 *******************
template <int ai, int bi, int ci, Regular A, Regular B, Regular C, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Domain<R, A>)
inline constexpr
auto&& select_1_3(A&& a, B&& b, C&& c, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_1_3_cb<ci, ai, bi>(std::forward<C>(c), std::forward<A>(a), std::forward<B>(b), r);
    return select_1_3_cb<ci, bi, ai>(std::forward<C>(c), std::forward<B>(b), std::forward<A>(a), r);
}

// find_44 *******************
template <int ai, int bi, int ci, int di, Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Domain<R, A>)
inline constexpr
auto&& select_2_4_da_cb(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_1_2<ai, ci>(std::forward<A>(a), std::forward<C>(c), r);
    return select_1_2<bi, di>(std::forward<B>(b), std::forward<D>(d), r);
}

// find_54 *******************
template <int ai, int bi, int ci, int di, int ei, Regular A, Regular B, Regular C, Regular D, Regular E, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Domain<R, A>)
inline constexpr
auto&& select_3_5_da_eb_ec(A&& a, B&& b, C&& c, D&& d, E&& e, R r) noexcept {
    compare_strict_or_reflexive<(bi < ci), R> cmp;
    if (cmp(b, c, r)) return select_2_4_da_cb<ai, ci, ei, di>(std::forward<A>(a), std::forward<C>(c), std::forward<E>(e), std::forward<D>(d), r);
    return select_2_4_da_cb<ai, bi, ei, di>(std::forward<A>(a), std::forward<B>(b), std::forward<E>(e), std::forward<D>(d), r);
}

// find_55 *******************
template <int ai, int bi, int ci, int di, Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Domain<R, A>)
inline constexpr
auto&& select_2_4_dc(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_2_4_da_cb<ai, ci, di, bi>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<B>(b), r);
    return select_2_4_da_cb<bi, ci, di, ai>(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<A>(a), r);
}

// find_53 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_4_7_ea_eb_gb_fc_gc_fd_gd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ei < fi), R> cmp;
    if (cmp(e, f, r)) return select_3_5_da_eb_ec<ai, ci, di, ei, gi>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), r);
    return select_2_4_dc<ai, fi, bi, gi>(std::forward<A>(a), std::forward<F>(f), std::forward<B>(b), std::forward<G>(g), r);
}

// find_26 *******************
template <int ai, int bi, int ci, int di, int ei, Regular A, Regular B, Regular C, Regular D, Regular E, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Domain<R, A>)
inline constexpr
auto&& select_2_5_ea_db_dc_ec(A&& a, B&& b, C&& c, D&& d, E&& e, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_1_3_cb<bi, ci, ei>(std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), r);
    return select_1_3_cb<ai, ci, di>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), r);
}

// find_28 *******************
template <int ai, int bi, int ci, int di, Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Domain<R, A>)
inline constexpr
auto&& select_1_4_da_cb(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_0_2<bi, di>(std::forward<B>(b), std::forward<D>(d), r);
    return select_0_2<ai, ci>(std::forward<A>(a), std::forward<C>(c), r);
}

// find_52 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Domain<R, A>)
inline constexpr
auto&& select_2_6_ea_fa_db_fb_dc_ec(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_1_4_da_cb<bi, ci, ei, fi>(std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), r);
    return select_1_4_da_cb<ai, ci, di, fi>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), r);
}

// find_51 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_fa_ga_db_fb_ec_fc_ge(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(di < ei), R> cmp;
    if (cmp(d, e, r)) return select_2_5_ea_db_dc_ec<ai, di, ci, ei, fi>(std::forward<A>(a), std::forward<D>(d), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), r);
    return select_2_6_ea_fa_db_fb_dc_ec<ai, bi, ei, di, gi, fi>(std::forward<A>(a), std::forward<B>(b), std::forward<E>(e), std::forward<D>(d), std::forward<G>(g), std::forward<F>(f), r);
}


// find_27 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Domain<R, A>)
inline constexpr
auto&& select_2_6_ca_ea_db_eb_fd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_1_3_cb<ci, bi, ei>(std::forward<C>(c), std::forward<B>(b), std::forward<E>(e), r);
    return select_1_4_da_cb<ai, di, fi, ei>(std::forward<A>(a), std::forward<D>(d), std::forward<F>(f), std::forward<E>(e), r);
}


// find_50 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Domain<R, A>)
inline constexpr
auto&& select_4_9_fa_ia_db_gb_fc_gc_ed_hf_ig(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    compare_strict_or_reflexive<(di < fi), R> cmp;
    if (cmp(d, f, r)) return select_3_7_fa_ga_db_fb_ec_fc_ge<ai, di, ci, ei, gi, fi, ii>(std::forward<A>(a), std::forward<D>(d), std::forward<C>(c), std::forward<E>(e), std::forward<G>(g), std::forward<F>(f), std::forward<I>(i), r);
    return select_2_6_ca_ea_db_eb_fd<fi, bi, hi, gi, di, ii>(std::forward<F>(f), std::forward<B>(b), std::forward<H>(h), std::forward<G>(g), std::forward<D>(d), std::forward<I>(i), r);
}

// find_49 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_ea_fb_hb_ec_gc_fd_gd_hg(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    compare_strict_or_reflexive<(ai < gi), R> cmp;
    if (cmp(a, g, r)) return select_4_7_ea_eb_gb_fc_gc_fd_gd<bi, di, ci, ai, fi, ei, gi>(std::forward<B>(b), std::forward<D>(d), std::forward<C>(c), std::forward<A>(a), std::forward<F>(f), std::forward<E>(e), std::forward<G>(g), r);
    return select_2_6_ca_ea_db_eb_fd<bi, gi, fi, ai, hi, ei>(std::forward<B>(b), std::forward<G>(g), std::forward<F>(f), std::forward<A>(a), std::forward<H>(h), std::forward<E>(e), r);
}

// find_46 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ha_ia_db_eb_fc_gc_hd_ge_if_ji(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < fi), R> cmp;
    if (cmp(d, f, r)) return select_4_8_ea_fb_hb_ec_gc_fd_gd_hg<ei, ai, ci, di, gi, hi, fi, ii>(std::forward<E>(e), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<G>(g), std::forward<H>(h), std::forward<F>(f), std::forward<I>(i), r);
    return select_4_9_fa_ia_db_gb_fc_gc_ed_hf_ig<ai, bi, fi, ei, gi, ii, di, ji, hi>(std::forward<A>(a), std::forward<B>(b), std::forward<F>(f), std::forward<E>(e), std::forward<G>(g), std::forward<I>(i), std::forward<D>(d), std::forward<J>(j), std::forward<H>(h), r);
}


// find_25 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_da_ga_cb_eb_fd_ge(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_2_5_ea_db_dc_ec<ci, ei, ai, gi, di>(std::forward<C>(c), std::forward<E>(e), std::forward<A>(a), std::forward<G>(g), std::forward<D>(d), r);
    return select_2_6_ca_ea_db_eb_fd<di, bi, fi, ei, ci, gi>(std::forward<D>(d), std::forward<B>(b), std::forward<F>(f), std::forward<E>(e), std::forward<C>(c), std::forward<G>(g), r);
}

// find_48 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_da_ja_fb_hb_ec_gc_gd_id_he_je_if_jf(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < ei), R> cmp;
    if (cmp(d, e, r)) return select_3_7_da_ga_cb_eb_fd_ge<bi, ci, gi, fi, ei, ii, hi>(std::forward<B>(b), std::forward<C>(c), std::forward<G>(g), std::forward<F>(f), std::forward<E>(e), std::forward<I>(i), std::forward<H>(h), r);
    return select_3_7_da_ga_cb_eb_fd_ge<ai, bi, hi, di, fi, gi, ji>(std::forward<A>(a), std::forward<B>(b), std::forward<H>(h), std::forward<D>(d), std::forward<F>(f), std::forward<G>(g), std::forward<J>(j), r);
}


// find_20 *******************
template <int ai, int bi, int ci, int di, int ei, Regular A, Regular B, Regular C, Regular D, Regular E, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Domain<R, A>)
inline constexpr
auto&& select_2_5_da_ea_cb_eb(A&& a, B&& b, C&& c, D&& d, E&& e, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_1_3_cb<ci, ai, ei>(std::forward<C>(c), std::forward<A>(a), std::forward<E>(e), r);
    return select_1_3_cb<di, bi, ei>(std::forward<D>(d), std::forward<B>(b), std::forward<E>(e), r);
}

// find_19 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_da_ea_cb_eb_fc_gd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_2_5_da_ea_cb_eb<ai, ci, fi, ei, di>(std::forward<A>(a), std::forward<C>(c), std::forward<F>(f), std::forward<E>(e), std::forward<D>(d), r);
    return select_2_5_da_ea_cb_eb<bi, di, gi, ei, ci>(std::forward<B>(b), std::forward<D>(d), std::forward<G>(g), std::forward<E>(e), std::forward<C>(c), r);
}

// find_23 *******************
template <int ai, int bi, int ci, int di, Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Domain<R, A>)
inline constexpr
auto&& select_1_4_cb_db(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    compare_strict_or_reflexive<(ai < ci), R> cmp;
    if (cmp(a, c, r)) return select_1_3_cb<ai, bi, di>(std::forward<A>(a), std::forward<B>(b), std::forward<D>(d), r);
    return select_0_2<ci, di>(std::forward<C>(c), std::forward<D>(d), r);
}

// find_18 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Domain<R, A>)
inline constexpr
auto&& select_3_8_da_ha_cb_gb_ec_hc_fd_gd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    compare_strict_or_reflexive<(ci < di), R> cmp;
    if (cmp(c, d, r)) return select_1_4_cb_db<ei, ai, di, hi>(std::forward<E>(e), std::forward<A>(a), std::forward<D>(d), std::forward<H>(h), r);
    return select_1_4_cb_db<fi, bi, ci, gi>(std::forward<F>(f), std::forward<B>(b), std::forward<C>(c), std::forward<G>(g), r);
}


// find_17 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Domain<R, A>)
inline constexpr
auto&& select_3_8_fa_ha_eb_fb_dc_ec_gd_hd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_3_8_da_ha_cb_gb_ec_hc_fd_gd<ai, ci, di, bi, gi, fi, ei, hi>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<B>(b), std::forward<G>(g), std::forward<F>(f), std::forward<E>(e), std::forward<H>(h), r);
    return select_3_7_da_ea_cb_eb_fc_gd<bi, ci, di, ai, ei, gi, fi>(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<A>(a), std::forward<E>(e), std::forward<G>(g), std::forward<F>(f), r);
}

// find_47 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_da_ha_eb_ib_fc_gc_gd_he_je_if_jf_ki(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(di < ii), R> cmp;
    if (cmp(d, i, r)) return select_5_10_da_ja_fb_hb_ec_gc_gd_id_he_je_if_jf<bi, ci, ai, ei, di, fi, hi, gi, ji, ii>(std::forward<B>(b), std::forward<C>(c), std::forward<A>(a), std::forward<E>(e), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h), std::forward<G>(g), std::forward<J>(j), std::forward<I>(i), r);
    return select_3_8_fa_ha_eb_fb_dc_ec_gd_hd<ai, ei, fi, ii, ji, hi, ki, di>(std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<I>(i), std::forward<J>(j), std::forward<H>(h), std::forward<K>(k), std::forward<D>(d), r);
}

// find_45 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_da_ea_fb_ib_gc_hc_he_jf_ig_jg_ki(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(di < fi), R> cmp;
    if (cmp(d, f, r)) return select_5_10_ha_ia_db_eb_fc_gc_hd_ge_if_ji<bi, ai, ci, di, ei, gi, hi, fi, ii, ki>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h), std::forward<F>(f), std::forward<I>(i), std::forward<K>(k), r);
    return select_5_11_da_ha_eb_ib_fc_gc_gd_he_je_if_jf_ki<ai, bi, ci, ei, fi, gi, hi, di, ii, ji, ki>(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<D>(d), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), r);
}

// find_34 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_fa_ga_fb_gb_dc_gc_ed(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ai < di), R> cmp;
    if (cmp(a, d, r)) return select_2_6_ca_ea_db_eb_fd<bi, ci, fi, di, gi, ei>(std::forward<B>(b), std::forward<C>(c), std::forward<F>(f), std::forward<D>(d), std::forward<G>(g), std::forward<E>(e), r);
    return select_1_3<ai, bi, ei>(std::forward<A>(a), std::forward<B>(b), std::forward<E>(e), r);
}

// find_35 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_da_cb_gb_fc_ed_gd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ai < ci), R> cmp;
    if (cmp(a, c, r)) return select_2_6_ca_ea_db_eb_fd<di, bi, ei, ci, gi, fi>(std::forward<D>(d), std::forward<B>(b), std::forward<E>(e), std::forward<C>(c), std::forward<G>(g), std::forward<F>(f), r);
    return select_1_3_cb<fi, ai, di>(std::forward<F>(f), std::forward<A>(a), std::forward<D>(d), r);
}


// find_29 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Domain<R, A>)
inline constexpr
auto&& select_4_9_fa_ga_db_eb_ec_fc_gd_he_if(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    compare_strict_or_reflexive<(di < fi), R> cmp;
    if (cmp(d, f, r)) return select_3_7_fa_ga_fb_gb_dc_gc_ed<ai, di, ci, ei, hi, gi, fi>(std::forward<A>(a), std::forward<D>(d), std::forward<C>(c), std::forward<E>(e), std::forward<H>(h), std::forward<G>(g), std::forward<F>(f), r);
    return select_3_7_da_cb_gb_fc_ed_gd<ai, bi, ei, fi, ii, hi, di>(std::forward<A>(a), std::forward<B>(b), std::forward<E>(e), std::forward<F>(f), std::forward<I>(i), std::forward<H>(h), std::forward<D>(d), r);
}

// find_32 *******************
template <int ai, int bi, int ci, int di, Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Domain<R, A>)
inline constexpr
auto&& select_2_4_db_dc(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_1_2<bi, ci>(std::forward<B>(b), std::forward<C>(c), r);
    return select_1_3_cb<ai, ci, di>(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), r);
}

// find_31 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Domain<R, A>)
inline constexpr
auto&& select_3_6_ca_da_eb_fe(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    compare_strict_or_reflexive<(ci < ei), R> cmp;
    if (cmp(c, e, r)) return select_2_4_db_dc<di, ci, bi, ei>(std::forward<D>(d), std::forward<C>(c), std::forward<B>(b), std::forward<E>(e), r);
    return select_2_5_da_ea_cb_eb<ai, ei, fi, di, ci>(std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<D>(d), std::forward<C>(c), r);
}

// find_30 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_fa_fb_gb_dc_ec_ge(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_3_6_ca_da_eb_fe<ci, ai, di, ei, bi, fi>(std::forward<C>(c), std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<B>(b), std::forward<F>(f), r);
    return select_3_7_da_ga_cb_eb_fd_ge<bi, ci, di, ai, ei, fi, gi>(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), r);
}

// find_14 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Domain<R, A>)
inline constexpr
auto&& select_4_9_ga_gb_hb_dc_ec_fd_he_ig(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    compare_strict_or_reflexive<(ai < di), R> cmp;
    if (cmp(a, d, r)) return select_4_9_fa_ga_db_eb_ec_fc_gd_he_if<bi, ci, ai, ei, di, gi, hi, fi, ii>(std::forward<B>(b), std::forward<C>(c), std::forward<A>(a), std::forward<E>(e), std::forward<D>(d), std::forward<G>(g), std::forward<H>(h), std::forward<F>(f), std::forward<I>(i), r);
    return select_3_7_fa_fb_gb_dc_ec_ge<ei, bi, di, fi, ai, hi, gi>(std::forward<E>(e), std::forward<B>(b), std::forward<D>(d), std::forward<F>(f), std::forward<A>(a), std::forward<H>(h), std::forward<G>(g), r);
}

// find_24 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Domain<R, A>)
inline constexpr
auto&& select_4_9_da_ia_eb_hb_ec_gc_gd_hd_fe_ie(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    compare_strict_or_reflexive<(di < ei), R> cmp;
    if (cmp(d, e, r)) return select_2_5_da_ea_cb_eb<bi, ci, gi, hi, ei>(std::forward<B>(b), std::forward<C>(c), std::forward<G>(g), std::forward<H>(h), std::forward<E>(e), r);
    return select_1_4_cb_db<fi, ai, di, ii>(std::forward<F>(f), std::forward<A>(a), std::forward<D>(d), std::forward<I>(i), r);
}

// find_16 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Domain<R, A>)
inline constexpr
auto&& select_4_9_ha_ia_db_gb_ec_ic_fd_id_ge_he(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    compare_strict_or_reflexive<(ai < di), R> cmp;
    if (cmp(a, d, r)) return select_4_9_da_ia_eb_hb_ec_gc_gd_hd_fe_ie<ci, bi, ai, ei, di, fi, hi, gi, ii>(std::forward<C>(c), std::forward<B>(b), std::forward<A>(a), std::forward<E>(e), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h), std::forward<G>(g), std::forward<I>(i), r);
    return select_3_7_da_ga_cb_eb_fd_ge<ci, di, fi, ei, ai, gi, ii>(std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<E>(e), std::forward<A>(a), std::forward<G>(g), std::forward<I>(i), r);
}

// find_15 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_4_10_da_ha_gb_ib_ec_gc_fd_he_ie_jg(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < gi), R> cmp;
    if (cmp(d, g, r)) return select_4_9_ha_ia_db_gb_ec_ic_fd_id_ge_he<bi, ai, ci, di, ei, fi, hi, ii, gi>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<I>(i), std::forward<G>(g), r);
    return select_3_8_fa_ha_eb_fb_dc_ec_gd_hd<ai, ei, bi, gi, ii, hi, ji, di>(std::forward<A>(a), std::forward<E>(e), std::forward<B>(b), std::forward<G>(g), std::forward<I>(i), std::forward<H>(h), std::forward<J>(j), std::forward<D>(d), r);
}

// find_13 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_4_10_ha_ia_db_eb_fc_hc_ge_if_jh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < fi), R> cmp;
    if (cmp(d, f, r)) return select_4_9_ga_gb_hb_dc_ec_fd_he_ig<ai, ci, bi, ei, di, gi, hi, fi, ji>(std::forward<A>(a), std::forward<C>(c), std::forward<B>(b), std::forward<E>(e), std::forward<D>(d), std::forward<G>(g), std::forward<H>(h), std::forward<F>(f), std::forward<J>(j), r);
    return select_4_10_da_ha_gb_ib_ec_gc_fd_he_ie_jg<bi, ai, ci, ei, fi, gi, hi, di, ii, ji>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<D>(d), std::forward<I>(i), std::forward<J>(j), r);
}

// find_37 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ea_ja_db_fb_gc_ic_if_hg_jg_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ei < hi), R> cmp;
    if (cmp(e, h, r)) return select_5_11_da_ea_fb_ib_gc_hc_he_jf_ig_jg_ki<bi, ai, ci, di, fi, ei, gi, ii, ji, hi, ki>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<E>(e), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), std::forward<H>(h), std::forward<K>(k), r);
    return select_4_10_ha_ia_db_eb_fc_hc_ge_if_jh<ai, bi, gi, di, fi, hi, ii, ji, ei, ki>(std::forward<A>(a), std::forward<B>(b), std::forward<G>(g), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<E>(e), std::forward<K>(k), r);
}

// find_43 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Domain<R, A>)
inline constexpr
auto&& select_3_6_ea_eb_fb_dc_fd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    compare_strict_or_reflexive<(ai < di), R> cmp;
    if (cmp(a, d, r)) return select_2_4_da_cb<bi, ci, di, ei>(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), r);
    return select_1_3_cb<ai, bi, fi>(std::forward<A>(a), std::forward<B>(b), std::forward<F>(f), r);
}

// find_42 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_eb_fb_dc_gc_fd_ge(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    compare_strict_or_reflexive<(ai < di), R> cmp;
    if (cmp(a, d, r)) return select_3_6_ea_eb_fb_dc_fd<ai, ci, bi, ei, di, gi>(std::forward<A>(a), std::forward<C>(c), std::forward<B>(b), std::forward<E>(e), std::forward<D>(d), std::forward<G>(g), r);
    return select_2_6_ca_ea_db_eb_fd<di, bi, ai, ei, fi, gi>(std::forward<D>(d), std::forward<B>(b), std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), r);
}

// find_41 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ea_ja_fb_hb_dc_hc_gd_jd_he_ie_if_jf(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < ei), R> cmp;
    if (cmp(d, e, r)) return select_3_7_eb_fb_dc_gc_fd_ge<gi, bi, ai, ei, fi, hi, ji>(std::forward<G>(g), std::forward<B>(b), std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<J>(j), r);
    return select_3_7_da_ea_cb_eb_fc_gd<bi, ci, di, fi, hi, gi, ii>(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h), std::forward<G>(g), std::forward<I>(i), r);
}

// find_40 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_da_ia_fb_ib_ec_hc_gd_ie_je_hf_jf_kh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(di < hi), R> cmp;
    if (cmp(d, h, r)) return select_5_10_ea_ja_fb_hb_dc_hc_gd_jd_he_ie_if_jf<ci, bi, ai, di, ei, fi, gi, ii, ji, hi>(std::forward<C>(c), std::forward<B>(b), std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), std::forward<H>(h), r);
    return select_3_8_fa_ha_eb_fb_dc_ec_gd_hd<ai, ei, fi, hi, ji, ii, ki, di>(std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<J>(j), std::forward<I>(i), std::forward<K>(k), std::forward<D>(d), r);
}

// find_39 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_da_ga_eb_ib_fc_gc_hd_je_if_jf_ki(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ei < gi), R> cmp;
    if (cmp(e, g, r)) return select_5_11_da_ia_fb_ib_ec_hc_gd_ie_je_hf_jf_kh<ai, ci, bi, di, ei, fi, hi, ii, gi, ji, ki>(std::forward<A>(a), std::forward<C>(c), std::forward<B>(b), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<I>(i), std::forward<G>(g), std::forward<J>(j), std::forward<K>(k), r);
    return select_4_9_ga_gb_hb_dc_ec_fd_he_ig<fi, bi, ai, di, gi, hi, ii, ei, ki>(std::forward<F>(f), std::forward<B>(b), std::forward<A>(a), std::forward<D>(d), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<E>(e), std::forward<K>(k), r);
}

// find_38 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_da_ja_eb_gb_fc_gc_ie_hf_jf_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(di < hi), R> cmp;
    if (cmp(d, h, r)) return select_5_11_da_ga_eb_ib_fc_gc_hd_je_if_jf_ki<bi, ai, ci, ei, di, fi, gi, ii, ji, hi, ki>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<E>(e), std::forward<D>(d), std::forward<F>(f), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), std::forward<H>(h), std::forward<K>(k), r);
    return select_4_10_ha_ia_db_eb_fc_hc_ge_if_jh<ai, bi, fi, gi, ei, hi, ii, ji, di, ki>(std::forward<A>(a), std::forward<B>(b), std::forward<F>(f), std::forward<G>(g), std::forward<E>(e), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<D>(d), std::forward<K>(k), r);
}

// find_10 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_fa_hb_ec_jc_gd_hd_ig_jg_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_ea_ja_db_fb_gc_ic_if_hg_jg_kj<ci, ai, di, fi, ei, bi, gi, ii, hi, ji, ki>(std::forward<C>(c), std::forward<A>(a), std::forward<D>(d), std::forward<F>(f), std::forward<E>(e), std::forward<B>(b), std::forward<G>(g), std::forward<I>(i), std::forward<H>(h), std::forward<J>(j), std::forward<K>(k), r);
    return select_5_11_da_ja_eb_gb_fc_gc_ie_hf_jf_kj<ci, bi, di, ei, ai, gi, hi, ii, fi, ji, ki>(std::forward<C>(c), std::forward<B>(b), std::forward<D>(d), std::forward<E>(e), std::forward<A>(a), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<F>(f), std::forward<J>(j), std::forward<K>(k), r);
}

// find_12 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_4_10_ea_ia_db_ib_fc_gc_hg_ji(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(di < ei), R> cmp;
    if (cmp(d, e, r)) return select_4_10_ha_ia_db_eb_fc_hc_ge_if_jh<ai, ci, bi, fi, gi, di, hi, ii, ei, ji>(std::forward<A>(a), std::forward<C>(c), std::forward<B>(b), std::forward<F>(f), std::forward<G>(g), std::forward<D>(d), std::forward<H>(h), std::forward<I>(i), std::forward<E>(e), std::forward<J>(j), r);
    return select_4_10_ha_ia_db_eb_fc_hc_ge_if_jh<bi, ci, ai, fi, gi, ei, hi, ii, di, ji>(std::forward<B>(b), std::forward<C>(c), std::forward<A>(a), std::forward<F>(f), std::forward<G>(g), std::forward<E>(e), std::forward<H>(h), std::forward<I>(i), std::forward<D>(d), std::forward<J>(j), r);
}

// find_11 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Domain<R, A>)
inline constexpr
auto&& select_4_10_ha_gb_fc_ic_ed_id_ji(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_4_10_ea_ia_db_ib_fc_gc_hg_ji<ci, di, ai, ei, fi, hi, bi, gi, ii, ji>(std::forward<C>(c), std::forward<D>(d), std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<B>(b), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), r);
    return select_4_10_ea_ia_db_ib_fc_gc_hg_ji<ci, di, bi, ei, fi, gi, ai, hi, ii, ji>(std::forward<C>(c), std::forward<D>(d), std::forward<B>(b), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<A>(a), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), r);
}

// find_9 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_gb_fc_jc_ed_hd_ih_jh_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < ei), R> cmp;
    if (cmp(a, e, r)) return select_5_11_fa_hb_ec_jc_gd_hd_ig_jg_kj<bi, ai, ci, di, fi, gi, hi, ei, ii, ji, ki>(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<E>(e), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), r);
    return select_4_10_ha_gb_fc_ic_ed_id_ji<bi, ei, ci, hi, ii, fi, ai, gi, ji, ki>(std::forward<B>(b), std::forward<E>(e), std::forward<C>(c), std::forward<H>(h), std::forward<I>(i), std::forward<F>(f), std::forward<A>(a), std::forward<G>(g), std::forward<J>(j), std::forward<K>(k), r);
}

// find_8 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_eb_gc_ic_fd_hd_jh_ki(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(hi < ii), R> cmp;
    if (cmp(h, i, r)) return select_5_11_gb_fc_jc_ed_hd_ih_jh_kj<ai, bi, ci, di, fi, gi, ei, hi, ji, ii, ki>(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<G>(g), std::forward<E>(e), std::forward<H>(h), std::forward<J>(j), std::forward<I>(i), std::forward<K>(k), r);
    return select_5_11_gb_fc_jc_ed_hd_ih_jh_kj<ai, bi, di, ci, gi, fi, ei, ii, ki, hi, ji>(std::forward<A>(a), std::forward<B>(b), std::forward<D>(d), std::forward<C>(c), std::forward<G>(g), std::forward<F>(f), std::forward<E>(e), std::forward<I>(i), std::forward<K>(k), std::forward<H>(h), std::forward<J>(j), r);
}

// find_7 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_hb_gc_fd_ie_je_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(bi < ci), R> cmp;
    if (cmp(b, c, r)) return select_5_11_eb_gc_ic_fd_hd_jh_ki<ai, di, bi, ei, fi, ii, hi, ji, ci, ki, gi>(std::forward<A>(a), std::forward<D>(d), std::forward<B>(b), std::forward<E>(e), std::forward<F>(f), std::forward<I>(i), std::forward<H>(h), std::forward<J>(j), std::forward<C>(c), std::forward<K>(k), std::forward<G>(g), r);
    return select_5_11_eb_gc_ic_fd_hd_jh_ki<ai, di, ci, ei, fi, ii, gi, ji, bi, ki, hi>(std::forward<A>(a), std::forward<D>(d), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<I>(i), std::forward<G>(g), std::forward<J>(j), std::forward<B>(b), std::forward<K>(k), std::forward<H>(h), r);
}

// find_6 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_kb_jc_id_he_gf(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(bi < ci), R> cmp;
    if (cmp(b, c, r)) return select_5_11_hb_gc_fd_ie_je_kj<ai, di, ei, fi, bi, gi, hi, ii, ki, ci, ji>(std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<B>(b), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<K>(k), std::forward<C>(c), std::forward<J>(j), r);
    return select_5_11_hb_gc_fd_ie_je_kj<ai, di, ei, fi, ci, gi, hi, ii, ji, bi, ki>(std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<C>(c), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<B>(b), std::forward<K>(k), r);
}

// find_5 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_kd_je_if_hg(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_kb_jc_id_he_gf<ci, ai, di, ei, fi, gi, hi, ii, ji, ki, bi>(std::forward<C>(c), std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<B>(b), r);
    return select_5_11_kb_jc_id_he_gf<ci, bi, di, ei, fi, gi, hi, ii, ji, ki, ai>(std::forward<C>(c), std::forward<B>(b), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<A>(a), r);
}

// find_4 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_kf_jg_ih(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_kd_je_if_hg<ci, di, ei, ai, fi, gi, hi, ii, ji, ki, bi>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<A>(a), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<B>(b), r);
    return select_5_11_kd_je_if_hg<ci, di, ei, bi, fi, gi, hi, ii, ji, ki, ai>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<B>(b), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<A>(a), r);
}

// find_3 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_kh_ji(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_kf_jg_ih<ci, di, ei, fi, gi, ai, hi, ii, ji, ki, bi>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<A>(a), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<B>(b), r);
    return select_5_11_kf_jg_ih<ci, di, ei, fi, gi, bi, hi, ii, ji, ki, ai>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<B>(b), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<A>(a), r);
}

// find_2 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_kj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_kh_ji<ci, di, ei, fi, gi, hi, ii, ai, ji, ki, bi>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<A>(a), std::forward<J>(j), std::forward<K>(k), std::forward<B>(b), r);
    return select_5_11_kh_ji<ci, di, ei, fi, gi, hi, ii, bi, ji, ki, ai>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<B>(b), std::forward<J>(j), std::forward<K>(k), std::forward<A>(a), r);
}

// find_1 *******************
template <int ai, int bi, int ci, int di, int ei, int fi, int gi, int hi, int ii, int ji, int ki, Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    compare_strict_or_reflexive<(ai < bi), R> cmp;
    if (cmp(a, b, r)) return select_5_11_kj<ci, di, ei, fi, gi, hi, ii, ji, ki, ai, bi>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<A>(a), std::forward<B>(b), r);
    return select_5_11_kj<ci, di, ei, fi, gi, hi, ii, ji, ki, bi, ai>(std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), std::forward<B>(b), std::forward<A>(a), r);
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<A, C> && Same<A, D> && Same<A, E> && Same<A, F> && Same<A, G> && Same<A, H> && Same<A, I> && Same<A, J> && Same<A, K> && Domain<R, A>)
inline constexpr
auto&& median_11(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    return select_5_11<0,1,2,3,4,5,6,7,8,9,10>(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k), r);
}

} // namespace tao::algorithm

using namespace tao::algorithm;

inline
bool lt(char a, char b) noexcept {
    return a < b;
}

int main(int argc, char** argv) {
    return median_11(
        argv[1][0], argv[1][1], argv[1][2], argv[1][3],
        argv[1][4], argv[1][5], argv[1][6], argv[1][7],
        argv[1][8], argv[1][9], argv[1][10], lt);
}
