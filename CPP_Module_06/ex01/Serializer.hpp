/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:12 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:13 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

# include <cstdint>

# include "Data.hpp"

class Serializer {
    public:
        virtual ~Serializer() = 0;

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer& src);
        Serializer&    operator=(const Serializer& rhs);
};

#endif  // SERIALIZER_HPP_
