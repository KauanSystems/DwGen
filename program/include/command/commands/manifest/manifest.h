#pragma once

#include <string_view>

namespace {

	inline constexpr std::string_view kSecurityNotice = R"(
	======================================================================================
	CRYPTOGRAPHIC SECURITY NOTICE: DICEWARE METHOD, QUANTUM COMPUTING & DISCLAIMER
	======================================================================================

	This notice alerts system administrators, security teams, and advanced users
	to the limitations of the Diceware method in the face of advancing quantum computing.
	Diceware generates passwords and passphrases through random dice rolls and the
	selection of words from a predefined list.
	In classical scenarios, its security directly depends on the total entropy obtained
	from the number of chosen words and the size of the dictionary.
	Short passphrases (such as three or four words) already lack sufficient entropy
	even against traditional brute-force attacks and optimized dictionaries.
	Even longer passphrases of six or seven words may lose their safety margin if the
	actual entropy is lower than theoretically estimated.
	Practical factors such as reduced wordlists, non-random human choices, or passphrase
	reuse drastically reduce the effective resilience of the method.
	Cryptographically relevant quantum computers represent a structural shift in
	search and cryptanalytic capabilities.
	In particular, Grover's algorithm provides a quadratic quantum speedup for
	unstructured search across key and password spaces.
	In practice, a search requiring N classical operations drops to approximately
	sqrt(N) quantum steps under ideal conditions.
	This means the effective bit-security level of a Diceware passphrase is cut in
	half against a capable quantum adversary.
	A passphrase with 64 bits of classical entropy offers only about 32 bits of
	effective security against a viable quantum attack.
	Even a strong 128-bit passphrase drops to the equivalent of 64-bit resistance,
	requiring a reassessment of long-term security policies.
	Data and credentials protected today that must remain confidential for many years
	face the risk of "harvest now, decrypt later" attacks.
	Furthermore, quantum attacks can be combined with massive classical infrastructure,
	statistical analysis, and contextual metadata leaks.
	The Diceware method is not inherently invalid for immediate human password use,
	provided it employs high entropy and strict randomness.
	However, it must not be treated as a quantum-proof defense for critical secrets
	or long-lived cryptographic keys.
	For high-risk authentication, prioritize strong cryptographic keys, phishing-resistant
	multi-factor authentication (MFA), and post-quantum standards.
	For machine secrets, tokens, and symmetric or asymmetric keys, adopt approved
	algorithms and parameters sized for the quantum era.
	When memorable passphrases are required, increase the word count to raise the
	entropy margin well above current minimum baselines.
	Ensure word selection uses a truly unpredictable source of randomness, avoiding
	biased dice or mental shortcuts.
	Avoid reusing the same Diceware passphrase across multiple services and combine it
	with access controls, periodic rotation, and rate limiting.
	Periodically review password policies and key management practices as cryptographic
	standards and quantum hardware mature.
	When in doubt about the criticality of the protected asset, treat a Diceware
	passphrase as a transitional measure and apply stronger cryptographic controls.

	DICEWARE APPLICATION DISCLAIMER:
	This Diceware application is provided "as is", without express or implied warranties
	of fitness for a particular purpose or absolute security. The application and its
	authors are not liable for any runtime errors, entropy failures, randomness flaws,
	or cracked, compromised, or leaked passwords, nor for any direct or indirect damages
	resulting from the use of generated passphrases.
	Responsibility for secure storage, rotation, proper usage, and risk assessment of
	the created credentials rests entirely with the user or responsible organization.

	======================================================================================
	)";

} // namespace.
