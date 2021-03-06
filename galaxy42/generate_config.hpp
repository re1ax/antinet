#ifndef GENERATE_CONFIG_HPP
#define GENERATE_CONFIG_HPP

#include "libs0.hpp"
#include "filestorage.hpp"
#include "crypto/crypto.hpp"


enum class e_crypto_strength : unsigned char {
	lowest = 0,
	fast,
	normal,
	high,
	highest,
};

class generate_config {
public:
	generate_config() = delete;
	/**
	 * @brief any_crypto_set Generate any combination of cryptographic keys
	 * @param keys Vector of keys type and count to generate
	 */
	static void any_crypto_set(const std::string &filename,
							   const std::vector<std::pair<antinet_crypto::t_crypto_system_type,int>> &keys,
							   bool default_location);
	/**
	 * @brief crypto_permanent Create set of permanent keys with ability to sign
	 * @param strength
	 */
	static void crypto_sign (const std::string &filename, e_crypto_strength strength);
	/**
	 * @brief crypto_current Create set of current keys with ability to make DH exchange
	 * @param strength
	 */
	static void crypto_exchange (const std::string &filename, e_crypto_strength strength);
};

#endif // GENERATE_CONFIG_HPP
