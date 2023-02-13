//! \file tao/algorithm/selection/select_5_11.hpp
// Tao.Algorithm
//
// Copyright Fernando Pelliccioni 2016-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAO_ALGORITHM_SELECTION_SELECT_5_11_HPP_
#define TAO_ALGORITHM_SELECTION_SELECT_5_11_HPP_

#include <tao/algorithm/concepts.hpp>
#include <tao/algorithm/type_attributes.hpp>

namespace tao::algorithm {

template <Regular A, Regular B, StrictWeakOrdering R>
    requires(Same<A, B> && Domain<R, A>)
inline constexpr
auto&& select_0_2(A&& a, B&& b, R r) noexcept {
    if (r(b, a)) return std::forward<B>(b);
    return std::forward<A>(a);
}

template <Regular A, Regular B, StrictWeakOrdering R>
    requires(Same<A, B> && Domain<R, A>)
inline constexpr
auto&& select_1_2(A&& a, B&& b, R r) noexcept {
    if (r(b, a)) return std::forward<A>(a);
    return std::forward<B>(b);
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Domain<R, A>)
inline constexpr
auto&& select_2_6_bc_ef_ac_bd_ae(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    if ( ! r(e, d)) {
        if ( ! r(d, a)) {
            // if ( ! r(d, c)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<D>(d);
            // }
            return select_0_2(std::forward<C>(c), std::forward<D>(d), r);
        } else {
            return std::forward<A>(a);
        }
    } else {
        if ( ! r(e, b)) {
            // if ( ! r(e, c)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<E>(e);
            // }
            return select_0_2(std::forward<C>(c), std::forward<E>(e), r);
        } else {
            // if ( ! r(f, b)) {
            //     return std::forward<B>(b);
            // } else {
            //     return std::forward<F>(f);
            // }
            return select_0_2(std::forward<B>(b), std::forward<F>(f), r);
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_ab_ef_dg_ad_cd_eb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(d, b)) {
        if ( ! r(f, c)) {
            if ( ! r(f, b)) {
                // if ( ! r(c, b)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<B>(b);
                // }
                return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
            } else {
                // if ( ! r(f, a)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<A>(a);
                // }
                return select_1_2(std::forward<A>(a), std::forward<F>(f), r);
            }
        } else {
            if ( ! r(c, b)) {
                // if ( ! r(f, b)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<B>(b);
                // }
                return select_1_2(std::forward<B>(b), std::forward<F>(f), r);
            } else {
                // if ( ! r(c, a)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<A>(a);
                // }
                return select_1_2(std::forward<A>(a), std::forward<C>(c), r);
            }
        }
    } else {
        if ( ! r(f, d)) {
            if ( ! r(e, d)) {
                // if ( ! r(g, e)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<E>(e), std::forward<G>(g), r);
            } else {
                return std::forward<D>(d);
            }
        } else {
            if ( ! r(c, a)) {
                // if ( ! r(f, c)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<F>(f), r);
            } else {
                // if ( ! r(f, a)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<A>(a);
                // }
                return select_1_2(std::forward<A>(a), std::forward<F>(f), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Domain<R, A>)
inline constexpr
auto&& select_2_4_ab(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    if ( ! r(d, c)) {
        if ( ! r(d, b)) {
            // if ( ! r(c, b)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<B>(b);
            // }
            return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
        } else {
            // if ( ! r(d, a)) {
            //     return std::forward<D>(d);
            // } else {
            //     return std::forward<A>(a);
            // }
            return select_1_2(std::forward<A>(a), std::forward<D>(d), r);
        }
    } else {
        if ( ! r(c, b)) {
            // if ( ! r(d, b)) {
            //     return std::forward<D>(d);
            // } else {
            //     return std::forward<B>(b);
            // }
            return select_1_2(std::forward<B>(b), std::forward<D>(d), r);
        } else {
            // if ( ! r(c, a)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<A>(a);
            // }
            return select_1_2(std::forward<A>(a), std::forward<C>(c), r);
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Domain<R, A>)
inline constexpr
auto&&  select_3_6_cd_da_bf_be(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    if ( ! r(e, a)) {
        if ( ! r(b, a)) {
            return std::forward<B>(b);
        } else {
            if ( ! r(f, a)) {
                return std::forward<A>(a);
            } else {
                // if ( ! r(f, d)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<F>(f), r);
            }
        }
    } else {
        if ( ! r(f, e)) {
            if ( ! r(f, d)) {
                // if ( ! r(e, d)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
            } else {
                // if ( ! r(f, c)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<F>(f), r);
            }
        } else {
            if ( ! r(e, d)) {
                // if ( ! r(f, d)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<F>(f), r);
            } else {
                // if ( ! r(e, c)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<E>(e), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Domain<R, A>)
inline constexpr
auto&& select_2_4_cd(A&& a, B&& b, C&& c, D&& d, R r) noexcept {
    if ( ! r(b, a)) {
        if ( ! r(d, b)) {
            // if ( ! r(c, b)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<B>(b);
            // }
            return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
        } else {
            // if ( ! r(d, a)) {
            //     return std::forward<D>(d);
            // } else {
            //     return std::forward<A>(a);
            // }
            return select_1_2(std::forward<A>(a), std::forward<D>(d), r);
        }
    } else {
        if ( ! r(d, a)) {
            // if ( ! r(c, a)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<A>(a);
            // }
            return select_1_2(std::forward<A>(a), std::forward<C>(c), r);
        } else {
            // if ( ! r(d, b)) {
            //     return std::forward<D>(d);
            // } else {
            //     return std::forward<B>(b);
            // }
            return select_1_2(std::forward<B>(b), std::forward<D>(d), r);
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Domain<R, A>)
inline constexpr
auto&&  select_3_6_bc_ce_df_da_af(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    if ( ! r(c, a)) {
        if ( ! r(f, b)) {
            // if ( ! r(f, c)) {
            //     return std::forward<C>(c);
            // } else {
            //     return std::forward<F>(f);
            // }
            return select_0_2(std::forward<C>(c), std::forward<F>(f), r);
        } else {
            return std::forward<B>(b);
        }
    } else {
        if ( ! r(e, a)) {
            return std::forward<A>(a);
        } else {
            // if ( ! r(e, d)) {
            //     return std::forward<E>(e);
            // } else {
            //     return std::forward<D>(d);
            // }
            return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Domain<R, A>)
inline constexpr
auto&&  select_3_6_bc_ce_df_da_fa(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    if ( ! r(c, a)) {
        // if ( ! r(b, a)) {
        //     return std::forward<B>(b);
        // } else {
        //     return std::forward<A>(a);
        // }
        return select_1_2(std::forward<A>(a), std::forward<B>(b), r);
    } else {
        if ( ! r(f, e)) {
            // if ( ! r(e, d)) {
            //     return std::forward<E>(e);
            // } else {
            //     return std::forward<D>(d);
            // }
            return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
        } else {
            // if ( ! r(f, c)) {
            //     return std::forward<F>(f);
            // } else {
            //     return std::forward<C>(c);
            // }
            return select_1_2(std::forward<C>(c), std::forward<F>(f), r);
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Domain<R, A>)
inline constexpr
auto&&  select_3_6_cd_da_fb_fe(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, R r) noexcept {
    if ( ! r(b, a)) {
        if ( ! r(e, a)) {
            // if ( ! r(f, a)) {
            //     return std::forward<F>(f);
            // } else {
            //     return std::forward<A>(a);
            // }
            return select_1_2(std::forward<A>(a), std::forward<F>(f), r);
        } else {
            // if ( ! r(e, d)) {
            //     return std::forward<E>(e);
            // } else {
            //     return std::forward<D>(d);
            // }
            return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
        }
    } else {
        if ( ! r(e, b)) {
            if ( ! r(e, d)) {
                // if ( ! r(d, b)) {
                //     return std::forward<D>(d);
                // } else {
                //     return std::forward<B>(b);
                // }
                return select_1_2(std::forward<B>(b), std::forward<D>(d), r);
            } else {
                // if ( ! r(e, c)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<E>(e), r);
            }
        } else {
            if ( ! r(d, b)) {
                // if ( ! r(c, b)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<B>(b);
                // }
                return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
            } else {
                // if ( ! r(e, d)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_4_7_ab_de_eb_af_cf(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(f, b)) {
        if ( ! r(c, a)) {
            if ( ! r(g, c)) {
                if ( ! r(g, b)) {
                    // if ( ! r(c, b)) {
                    //     return std::forward<C>(c);
                    // } else {
                    //     return std::forward<B>(b);
                    // }
                    return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
                } else {
                    // if ( ! r(g, e)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<E>(e);
                    // }
                    return select_1_2(std::forward<E>(e), std::forward<G>(g), r);
                }
            } else {
                if ( ! r(c, b)) {
                    // if ( ! r(g, b)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<B>(b);
                    // }
                    return select_1_2(std::forward<B>(b), std::forward<G>(g), r);
                } else {
                    // if ( ! r(e, c)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<C>(c);
                    // }
                    return select_1_2(std::forward<C>(c), std::forward<E>(e), r);
                }
            }
        } else {
            if ( ! r(e, a)) {
                if ( ! r(g, b)) {
                    return std::forward<B>(b);
                } else {
                    // if ( ! r(g, e)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<E>(e);
                    // }
                    return select_1_2(std::forward<E>(e), std::forward<G>(g), r);
                }
            } else {
                if ( ! r(g, a)) {
                    // if ( ! r(g, b)) {
                    //     return std::forward<B>(b);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<B>(b), std::forward<G>(g), r);
                } else {
                    return std::forward<A>(a);
                }
            }
        }
    } else {
        if ( ! r(g, e)) {
            if ( ! r(c, a)) {
                if ( ! r(g, f)) {
                    // if ( ! r(f, e)) {
                    //     return std::forward<F>(f);
                    // } else {
                    //     return std::forward<E>(e);
                    // }
                    return select_1_2(std::forward<E>(e), std::forward<F>(f), r);
                } else {
                    // if ( ! r(g, c)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<C>(c);
                    // }
                    return select_1_2(std::forward<C>(c), std::forward<G>(g), r);
                }
            } else {
                if ( ! r(g, f)) {
                    // if ( ! r(f, e)) {
                    //     return std::forward<F>(f);
                    // } else {
                    //     return std::forward<E>(e);
                    // }
                    return select_1_2(std::forward<E>(e), std::forward<F>(f), r);
                } else {
                    // if ( ! r(g, a)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<A>(a);
                    // }
                    return select_1_2(std::forward<A>(a), std::forward<G>(g), r);
                }
            }
        } else {
            if ( ! r(f, e)) {
                if ( ! r(c, a)) {
                    // if ( ! r(e, c)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<C>(c);
                    // }
                    return select_1_2(std::forward<C>(c), std::forward<E>(e), r);
                } else {
                    // if ( ! r(e, a)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<A>(a);
                    // }
                    return select_1_2(std::forward<A>(a), std::forward<E>(e), r);
                }
            } else {
                if ( ! r(f, d)) {
                    // if ( ! r(g, f)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<F>(f);
                    // }
                    return select_1_2(std::forward<F>(f), std::forward<G>(g), r);
                } else {
                    // if ( ! r(g, d)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<D>(d);
                    // }
                    return select_1_2(std::forward<D>(d), std::forward<G>(g), r);
                }
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_cd_ef_df_da_eb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(b, a)) {
        if ( ! r(f, a)) {
            if ( ! r(g, e)) {
                if ( ! r(g, a)) {
                    // if ( ! r(e, a)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<A>(a);
                    // }
                    return select_1_2(std::forward<A>(a), std::forward<E>(e), r);
                } else {
                    // if ( ! r(g, d)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<D>(d);
                    // }
                    return select_1_2(std::forward<D>(d), std::forward<G>(g), r);
                }
            } else {
                if ( ! r(e, a)) {
                    // if ( ! r(g, a)) {
                    //     return std::forward<G>(g);
                    // } else {
                    //     return std::forward<A>(a);
                    // }
                    return select_1_2(std::forward<A>(a), std::forward<G>(g), r);
                } else {
                    // if ( ! r(e, d)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<D>(d);
                    // }
                    return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
                }
            }
        } else {
            if ( ! r(e, d)) {
                if ( ! r(g, e)) {
                    // if ( ! r(g, f)) {
                    //     return std::forward<F>(f);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<F>(f), std::forward<G>(g), r);
                } else {
                    return std::forward<E>(e);
                }
            } else {
                if ( ! r(g, d)) {
                    // if ( ! r(g, f)) {
                    //     return std::forward<F>(f);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<F>(f), std::forward<G>(g), r);
                } else {
                    return std::forward<D>(d);
                }
            }
        }
    } else {
        if ( ! r(g, b)) {
            if ( ! r(c, b)) {
                if ( ! r(g, c)) {
                    // if ( ! r(g, d)) {
                    //     return std::forward<D>(d);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<D>(d), std::forward<G>(g), r);
                } else {
                    return std::forward<C>(c);
                }
            } else {
                if ( ! r(d, b)) {
                    // if ( ! r(g, d)) {
                    //     return std::forward<D>(d);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<D>(d), std::forward<G>(g), r);
                } else {
                    // if ( ! r(f, b)) {
                    //     return std::forward<B>(b);
                    // } else {
                    //     return std::forward<F>(f);
                    // }
                    return select_0_2(std::forward<B>(b), std::forward<F>(f), r);
                }
            }
        } else {
            if ( ! r(g, d)) {
                if ( ! r(g, e)) {
                    // if ( ! r(g, f)) {
                    //     return std::forward<F>(f);
                    // } else {
                    //     return std::forward<G>(g);
                    // }
                    return select_0_2(std::forward<F>(f), std::forward<G>(g), r);
                } else {
                    return std::forward<E>(e);
                }
            } else {
                if ( ! r(d, b)) {
                    // if ( ! r(c, b)) {
                    //     return std::forward<C>(c);
                    // } else {
                    //     return std::forward<B>(b);
                    // }
                    return select_1_2(std::forward<B>(b), std::forward<C>(c), r);
                } else {
                    // if ( ! r(e, d)) {
                    //     return std::forward<E>(e);
                    // } else {
                    //     return std::forward<D>(d);
                    // }
                    return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
                }
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_4_7_bc_ef_cf_dg_da_ea(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(g, a)) {
        if ( ! r(c, a)) {
            if ( ! r(g, b)) {
                // if ( ! r(g, c)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<C>(c), std::forward<G>(g), r);
            } else {
                return std::forward<B>(b);
            }
        } else {
            if ( ! r(f, a)) {
                return std::forward<A>(a);
            } else {
                // if ( ! r(f, d)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<F>(f), r);
            }
        }
    } else {
        if ( ! r(g, c)) {
            if ( ! r(g, f)) {
                // if ( ! r(f, d)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<F>(f), r);
            } else {
                // if ( ! r(g, e)) {
                //     return std::forward<G>(g);
                // } else {
                //     return std::forward<E>(e);
                // }
                return select_1_2(std::forward<E>(e), std::forward<G>(g), r);
            }
        } else {
            if ( ! r(c, a)) {
                // if ( ! r(b, a)) {
                //     return std::forward<B>(b);
                // } else {
                //     return std::forward<A>(a);
                // }
                return select_1_2(std::forward<A>(a), std::forward<B>(b), r);
            } else {
                // if ( ! r(e, c)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<E>(e), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_ab_ef_dg_da_ea_cg(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(f, a)) {
        if ( ! r(c, a)) {
            if ( ! r(c, b)) {
                // if ( ! r(f, b)) {
                //     return std::forward<B>(b);
                // } else {
                //     return std::forward<F>(f);
                // }
                return select_0_2(std::forward<B>(b), std::forward<F>(f), r);
            } else {
                // if ( ! r(f, c)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<F>(f);
                // }
                return select_0_2(std::forward<C>(c), std::forward<F>(f), r);
            }
        } else {
            if ( ! r(g, a)) {
                return std::forward<A>(a);
            } else {
                // if ( ! r(g, e)) {
                //     return std::forward<G>(g);
                // } else {
                //     return std::forward<E>(e);
                // }
                return select_1_2(std::forward<E>(e), std::forward<G>(g), r);
            }
        }
    } else {
        if ( ! r(f, c)) {
            if ( ! r(g, f)) {
                // if ( ! r(f, d)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<F>(f), r);
            } else {
                // if ( ! r(g, e)) {
                //     return std::forward<G>(g);
                // } else {
                //     return std::forward<E>(e);
                // }
                return select_1_2(std::forward<E>(e), std::forward<G>(g), r);
            }
        } else {
            if ( ! r(c, a)) {
                return std::forward<A>(a);
            } else {
                // if ( ! r(d, c)) {
                //     return std::forward<D>(d);
                // } else {
                //     return std::forward<C>(c);
                // }
                return select_1_2(std::forward<C>(c), std::forward<D>(d), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_3_7_ab_de_ef_eb_gc_ac(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(e, a)) {
        if ( ! r(g, e)) {
            if ( ! r(f, b)) {
                // if ( ! r(g, b)) {
                //     return std::forward<B>(b);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<B>(b), std::forward<G>(g), r);
            } else {
                // if ( ! r(g, f)) {
                //     return std::forward<F>(f);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<F>(f), std::forward<G>(g), r);
            }
        } else {
            if ( ! r(d, c)) {
                return std::forward<D>(d);
            } else {
                // if ( ! r(e, c)) {
                //     return std::forward<C>(c);
                // } else {
                //     return std::forward<E>(e);
                // }
                return select_0_2(std::forward<C>(c), std::forward<E>(e), r);
            }
        }
    } else {
        if ( ! r(g, f)) {
            if ( ! r(f, a)) {
                // if ( ! r(f, b)) {
                //     return std::forward<B>(b);
                // } else {
                //     return std::forward<F>(f);
                // }
                return select_0_2(std::forward<B>(b), std::forward<F>(f), r);
            } else {
                // if ( ! r(g, a)) {
                //     return std::forward<A>(a);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<A>(a), std::forward<G>(g), r);
            }
        } else {
            if ( ! r(g, a)) {
                // if ( ! r(g, b)) {
                //     return std::forward<B>(b);
                // } else {
                //     return std::forward<G>(g);
                // }
                return select_0_2(std::forward<B>(b), std::forward<G>(g), r);
            } else {
                // if ( ! r(f, a)) {
                //     return std::forward<A>(a);
                // } else {
                //     return std::forward<F>(f);
                // }
                return select_0_2(std::forward<A>(a), std::forward<F>(f), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Domain<R, A>)
inline constexpr
auto&& select_4_7_cd_ef_df_ea_gb_ba(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, R r) noexcept {
    if ( ! r(c, a)) {
        return std::forward<C>(c);
    } else {
        if ( ! r(d, b)) {
            if ( ! r(d, a)) {
                return std::forward<A>(a);
            } else {
                // if ( ! r(e, d)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<D>(d);
                // }
                return select_1_2(std::forward<D>(d), std::forward<E>(e), r);
            }
        } else {
            if ( ! r(f, b)) {
                // if ( ! r(e, b)) {
                //     return std::forward<E>(e);
                // } else {
                //     return std::forward<B>(b);
                // }
                return select_1_2(std::forward<B>(b), std::forward<E>(e), r);
            } else {
                // if ( ! r(g, f)) {
                //     return std::forward<G>(g);
                // } else {
                //     return std::forward<F>(f);
                // }
                return select_1_2(std::forward<F>(f), std::forward<G>(g), r);
            }
        }
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_3_8_bc_fg_ac_dg_da_eh_be_af(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(h, a)) {
        return select_2_6_bc_ef_ac_bd_ae(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g),r);
    } else {
        return select_1_2(std::forward<D>(d), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Domain<R, A>)
inline constexpr
auto&& select_5_9_ab_de_gh_eh_eb_fi_af_cf_gb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    if (!r(f, e)) {
        return select_3_7_ab_ef_dg_ad_cd_eb(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i),r);
    } else {
        return select_2_4_ab(std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<I>(i),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ag_cg(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(h, b)) {
        return select_3_8_bc_fg_ac_dg_da_eh_be_af(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_9_ab_de_gh_eh_eb_fi_af_cf_gb(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_cd_fg_dg_da_eh_eb_bh_fb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(b, a)) {
        return select_2_4_cd(std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g),r);
    } else {
        return select_3_6_bc_ce_df_da_af(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_cd_fg_dg_da_eh_eb_bh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(f, b)) {
        return select_3_6_cd_da_bf_be(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h),r);
    } else {
        return select_4_8_cd_fg_dg_da_eh_eb_bh_fb(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_cd_fg_dg_da_eh_eb_hb_fh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(h, a)) {
        return select_2_4_cd(std::forward<A>(a), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g),r);
    } else {
        return select_3_6_bc_ce_df_da_fa(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_cd_fg_dg_da_eh_eb_hb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(h, f)) {
        return select_4_8_cd_fg_dg_da_eh_eb_hb_fh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    } else {
        return select_3_6_cd_da_fb_fe(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_cd_fg_dg_da_eh_eb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(h, b)) {
        return select_4_8_cd_fg_dg_da_eh_eb_bh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    } else {
        return select_4_8_cd_fg_dg_da_eh_eb_hb(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ag(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(g, c)) {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ag_cg(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_4_8_cd_fg_dg_da_eh_eb(std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_ab_de_fg_eg_eb_af(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(f, c)) {
        return select_4_7_ab_de_eb_af_cf(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h),r);
    } else {
        return select_3_7_cd_ef_df_da_eb(std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Domain<R, A>)
inline constexpr
auto&& select_5_9_ab_de_gh_eh_eb_fi_fa_ga_ci(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    if (!r(e, c)) {
        return select_4_7_bc_ef_cf_dg_da_ea(std::forward<A>(a), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i),r);
    } else {
        return select_3_7_ab_ef_dg_da_ea_cg(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Domain<R, A>)
inline constexpr
auto&& select_4_8_ab_de_fg_eg_eb_fa_hc(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, R r) noexcept {
    if (!r(c, a)) {
        return select_3_7_ab_de_ef_eb_gc_ac(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h),r);
    } else {
        return select_4_7_cd_ef_df_ea_gb_ba(std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Domain<R, A>)
inline constexpr
auto&& select_5_9_ab_de_gh_eh_eb_fi_fa_ga(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, R r) noexcept {
    if (!r(i, c)) {
        return select_5_9_ab_de_gh_eh_eb_fi_fa_ga_ci(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i),r);
    } else {
        return select_4_8_ab_de_fg_eg_eb_fa_hc(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ga(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(h, a)) {
        return select_4_8_ab_de_fg_eg_eb_af(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_9_ab_de_gh_eh_eb_fi_fa_ga(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi_fb_gj(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(g, a)) {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ag(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb_gj_ga(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi_fb(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(j, g)) {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb_gj(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb_gj(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<J>(j), std::forward<H>(h), std::forward<I>(i), std::forward<G>(g),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd_fi(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(b, f)) {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_10_ab_cd_ef_hi_bd_fi_fb(std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<I>(i), std::forward<A>(a), std::forward<B>(b), std::forward<G>(g), std::forward<C>(c), std::forward<D>(d), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Domain<R, A>)
inline constexpr
auto&& select_5_10_ab_cd_ef_hi_bd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, R r) noexcept {
    if (!r(i, f)) {
        return select_5_10_ab_cd_ef_hi_bd_fi(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j),r);
    } else {
        return select_5_10_ab_cd_ef_hi_bd_fi(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<H>(h), std::forward<I>(i), std::forward<G>(g), std::forward<E>(e), std::forward<F>(f), std::forward<J>(j),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd_ef_gh_ij_bd_fh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(h, d)) {
        return select_5_10_ab_cd_ef_hi_bd(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_10_ab_cd_ef_hi_bd(std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd_ef_gh_ij_bd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(h, f)) {
        return select_5_11_ab_cd_ef_gh_ij_bd_fh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd_ef_gh_ij_bd_fh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<G>(g), std::forward<H>(h), std::forward<E>(e), std::forward<F>(f), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd_ef_gh_ij(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(d, b)) {
        return select_5_11_ab_cd_ef_gh_ij_bd(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd_ef_gh_ij_bd(std::forward<C>(c), std::forward<D>(d), std::forward<A>(a), std::forward<B>(b), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd_ef_gh(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(j, i)) {
        return select_5_11_ab_cd_ef_gh_ij(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd_ef_gh_ij(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<J>(j), std::forward<I>(i), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd_ef(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(h, g)) {
        return select_5_11_ab_cd_ef_gh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd_ef_gh(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<H>(h), std::forward<G>(g), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab_cd(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(f, e)) {
        return select_5_11_ab_cd_ef(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd_ef(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<F>(f), std::forward<E>(e), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11_ab(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(d, c)) {
        return select_5_11_ab_cd(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab_cd(std::forward<A>(a), std::forward<B>(b), std::forward<D>(d), std::forward<C>(c), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

template <Regular A, Regular B, Regular C, Regular D, Regular E, Regular F, Regular G, Regular H, Regular I, Regular J, Regular K, StrictWeakOrdering R>
    requires(Same<A, B> && Same<B, C> && Same<C, D> && Same<D, E> && Same<E, F> && Same<F, G> && Same<G, H> && Same<H, I> && Same<I, J> && Same<J, K> && Domain<R, A>)
inline constexpr
auto&& select_5_11(A&& a, B&& b, C&& c, D&& d, E&& e, F&& f, G&& g, H&& h, I&& i, J&& j, K&& k, R r) noexcept {
    if ( ! r(b, a)) {
        return select_5_11_ab(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    } else {
        return select_5_11_ab(std::forward<B>(b), std::forward<A>(a), std::forward<C>(c), std::forward<D>(d), std::forward<E>(e), std::forward<F>(f), std::forward<G>(g), std::forward<H>(h), std::forward<I>(i), std::forward<J>(j), std::forward<K>(k),r);
    }
}

} // namespace tao::algorithm

#endif // TAO_ALGORITHM_SELECTION_SELECT_5_11_HPP_
